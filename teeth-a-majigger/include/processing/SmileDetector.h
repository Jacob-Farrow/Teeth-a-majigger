#ifndef TEETH_SMILEDETECTOR_H
#define TEETH_SMILEDETECTOR_H

#include <opencv2/opencv.hpp>

/**
 * @class SmileDetector
 * @brief A class for detecting smiles in video frames.
 *
 * The `SmileDetector` class uses OpenCV's CascadeClassifier to detect faces
 * and smiles in a given video frame. It provides functionality to load
 * pre-trained Haar cascades and perform smile detection.
 */
class SmileDetector {
    cv::CascadeClassifier faceCascade; ///< Haar cascade for face detection.
    cv::CascadeClassifier smileCascade; ///< Haar cascade for smile detection.

public:
    SmileDetector();

    /**
     * @brief Detects smiles in a given video frame.
     *
     * This function processes the input frame to detect faces and smiles
     * within those faces. It returns a vector of rectangles representing
     * the regions where smiles were detected.
     *
     * @param frame The input video frame (in BGR or grayscale format) to
     *              analyze for smile detection.
     * @return A vector of `cv::Rect` objects representing the bounding boxes
     *         of detected smiles.
     */
    std::vector<cv::Rect> detectSmiles(const cv::Mat& frame);
};
#endif //TEETH_SMILEDETECTOR_H
