
#include "VideoCaptureManager.h"

int main() {

    VideoCaptureManager captureManager(0); // Initialize with camera index 0

    captureManager.startCapture(); // Start capturing video

    while (captureManager.isCapturing()) {
    }

    captureManager.stopCapture(); // Stop capturing video when done

    return 0; // Exit the application
}