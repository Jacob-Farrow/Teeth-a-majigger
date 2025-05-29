#include "VideoCaptureManager.h"

VideoCaptureManager::VideoCaptureManager(int cameraIndex) {
    camera = new Camera(cameraIndex, new FrameProcessor(), new SmileDetector(), new Visualiser());
}

VideoCaptureManager::~VideoCaptureManager() {
    if (camera) delete camera;
}

void VideoCaptureManager::startCapture() {
    if (camera) {
        camera->start();
        return;
    }
    std::cerr << "Error: Camera not initialized." << std::endl;
}

void VideoCaptureManager::stopCapture() {
    if (camera) {
        camera->stop();
        return;
    }
    std::cerr << "Error: Camera not initialized." << std::endl;
}

bool VideoCaptureManager::isCapturing() const {
    if(!camera) {
        std::cerr << "Error: Camera not initialized." << std::endl;
        return false;
    }
    return camera->isCapturing();
}
