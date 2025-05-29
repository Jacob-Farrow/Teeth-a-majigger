#ifndef TEETH_FRAMEPROCESSOR_H
#define TEETH_FRAMEPROCESSOR_H

#include <opencv2/opencv.hpp>

/**
 * @class SmileDetector
 * @brief A class for detecting smiles in video frames.
 *
 * The `SmileDetector` class uses OpenCV's CascadeClassifier to detect faces
 * and smiles in a given video frame. It provides functionality to load
 * pre-trained Haar cascades and perform smile detection.
 */
class FrameProcessor {
    static const int frameWidth = 320;  ///< Width to which frames are resized during preprocessing.
    static const int frameHeight = 240; ///< Height to which frames are resized during preprocessing.
    cv::Mat imgOrig; ///< Original frame captured from the camera.
    cv::Mat imgGrey; ///< Grayscale version of the original frame.

public:
    FrameProcessor();

    ~FrameProcessor() = default;

    /**
     * @brief Preprocesses the input frame by resizing, converting to grayscale, and applying background subtraction.
     *
     * This function takes a raw frame captured from the camera and performs
     * preprocessing steps to prepare it for further analysis. The preprocessing
     * includes resizing the frame to a fixed size, converting it to grayscale,
     * and applying background subtraction.
     *
     * @param rawFrame The raw frame captured from the camera.
     * @return A `cv::Mat` object representing the preprocessed frame.
     */
    cv::Mat preprocess(const cv::Mat &rawFrame);


};



#endif //TEETH_FRAMEPROCESSOR_H
