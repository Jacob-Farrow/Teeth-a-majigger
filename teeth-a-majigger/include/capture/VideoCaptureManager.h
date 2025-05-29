#ifndef TEETH_VIDEOCAPTUREMANAGER_H
#define TEETH_VIDEOCAPTUREMANAGER_H

#include "Camera.h"

/**
 * @class VideoCaptureManager
 * @brief Manages video capture operations using one or more cameras.
 *
 * The `VideoCaptureManager` class provides functionality to start, stop, and
 * monitor video capture processes. It interacts with the `Camera` class to
 * handle the underlying camera operations.
 */
class VideoCaptureManager {
    Camera* camera; ///< Camera object for video capture.

public:
    explicit VideoCaptureManager(int cameraIndex = 0);

    ~VideoCaptureManager();

    /**
     * @brief Starts the video capture process for both cameras.
     */
    void startCapture();

    /**
     * @brief Stops the video capture process for both cameras.
     */
    void stopCapture();

    /**
     * @brief Checks if both cameras are currently capturing frames.
     * @return True if both cameras are capturing, false otherwise.
     */
    [[nodiscard]] bool isCapturing() const;




};



#endif //TEETH_VIDEOCAPTUREMANAGER_H
