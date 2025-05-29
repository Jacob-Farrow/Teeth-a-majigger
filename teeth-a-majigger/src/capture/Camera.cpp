#include "Camera.h"

Camera::Camera(int index, FrameProcessor *frameProcessor,
               SmileDetector *smileDetector, Visualiser *visualiser): bIsCapturing(false),
               frameProcessor(frameProcessor), smileDetector(smileDetector), visualiser(visualiser) {
    if(!capture.open(index)) {
        std::cerr << "Error: Could not open camera at index: " << index << std::endl;
        return;
    }

    cameraIndex = index;

    capture.set(cv::CAP_PROP_FPS, 25);

    name = std::format("Video Capture\t {}\n", index);
    std::cout << name << "Camera opened successfully." << std::endl;
}

Camera::~Camera() {
    stop();
    release();
    delete frameProcessor;
    delete smileDetector;
    delete visualiser;
}

void Camera::start() {
    bIsCapturing = true;
    captureThread = std::thread(&Camera::captureLoop, this);
}

void Camera::captureLoop() {
    while (bIsCapturing) {
        cv::Mat tempFrame;
        capture >> tempFrame;
        if (tempFrame.empty()) break;

        processFrame(tempFrame);
        {
            std::lock_guard<std::mutex> lock(frameMutex);
        }
        if (cv::waitKey(30) >= 0) stop();
    }
}

void Camera::processFrame(const cv::Mat &tempFrame) {
    const cv::Mat processedFrame = frameProcessor->preprocess(tempFrame);

    std::vector<cv::Rect> smileRegions = smileDetector->detectSmiles(processedFrame);

    visualiser->renderVisuals(processedFrame, smileRegions);

    {
        std::lock_guard<std::mutex> lock(frameMutex);
        frame = processedFrame.clone();
    }
}

void Camera::stop() {
    bIsCapturing = false;
    if (captureThread.joinable()) {
        captureThread.join();
    }
    cv::destroyAllWindows();
}

bool Camera::isCapturing() const {
    return bIsCapturing;
}

void Camera::release() {
    if (capture.isOpened()) {
        capture.release();
        std::cout << name << "Camera released successfully." << std::endl;
    } else {
        std::cerr << name << "Camera was not open." << std::endl;
    }
}
