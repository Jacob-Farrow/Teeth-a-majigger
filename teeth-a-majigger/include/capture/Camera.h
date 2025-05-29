#ifndef TEETH_CAMERA_H
#define TEETH_CAMERA_H

#include <thread>
#include <string>
#include <opencv2/opencv.hpp>
#include "FrameProcessor.h"
#include "SmileDetector.h"
#include "Visualiser.h"


/**
 * @class Camera
 * @brief Handles video capture from a camera device, including frame acquisition,
 *        threading for continuous capture, and integration with an inference system.
 */
class Camera{
    static const int frameWidth = 320; ///< Width of the captured frame.
    static const int frameHeight = 240; ///< Height of the captured frame.

    std::string name{}; ///< Name or identifier for the camera.

    int cameraIndex; ///< Index of the camera device.

    cv::VideoCapture capture; ///< OpenCV VideoCapture object for accessing the camera.
    cv::Mat frame; ///< Stores the most recent frame captured from the camera.

    std::thread captureThread; ///< Thread for running the frame capture loop.
    std::mutex frameMutex; ///< Mutex to ensure thread-safe access to the frame.
    bool bIsCapturing; ///< Flag indicating whether the camera is actively capturing frames.

    FrameProcessor* frameProcessor; ///< Frame processor for image processing tasks.
    SmileDetector* smileDetector; ///< Smile detector for detecting smiles in the captured frames.
    Visualiser* visualiser; ///< Visualiser for rendering debug visuals.


    /**
     * @brief Internal loop for continuously capturing frames from the camera.
     *        Runs in a separate thread when capturing is active.
     */
    void captureLoop();

    /**
     * @brief Processes the captured frame, applying various image processing techniques.
     * @param tempFrame The frame captured from the camera.
     */
    void processFrame(const cv::Mat &tempFrame);

public:
    /**
     * @brief Constructs a Camera object and initializes the video capture device.
     * @param index The index of the camera device to open.
     * @param frameProcessor Pointer to a FrameProcessor object for processing frames.
     */
    Camera(int index, FrameProcessor* frameProcessor,
           SmileDetector* smileDetector, Visualiser* visualiser);

    /**
     * @brief Destructor to clean up resources and stop capturing if active.
     */
    ~Camera();

    /**
     * @brief Starts the frame capture process in a separate thread.
     */
    void start();

    /**
     * @brief Stops the frame capture process and joins the capture thread.
     */
    void stop();

    /**
     * @brief Checks if the camera is currently capturing frames.
     * @return True if capturing is active, false otherwise.
     */
    [[nodiscard]] bool isCapturing() const;

    /**
     * @brief Releases the video capture device.
     */
    void release();
};
#endif //TEETH_CAMERA_H
