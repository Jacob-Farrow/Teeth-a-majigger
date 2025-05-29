#ifndef TEETH_VISUALISER_H
#define TEETH_VISUALISER_H

#include <opencv2/opencv.hpp>

/**
 * @class Visualiser
 * @brief A class responsible for rendering visual elements on video frames.
 *
 * The `Visualiser` class provides functionality to overlay visual elements,
 * such as rectangles or other graphics, on processed video frames. It is
 * primarily used for visualizing detected regions (e.g., smiles or teeth)
 * in a video feed.
 */
class Visualiser {
    static const int frameWidth = 320; ///< Width of the frame used for visualization.

public:
    Visualiser() = default;
    ~Visualiser() = default;

    /**
    * @brief Renders visual elements on a processed video frame.
    *
    * This function overlays visual elements, such as rectangles, on the
    * provided processed frame based on the detected smile regions.
    *
    * @param processedFrame The input video frame that has been preprocessed
    *                       (e.g., converted to grayscale or resized).
    * @param smileRegions A vector of rectangles representing the regions
    *                     where smiles have been detected.
    */
    void renderVisuals(const cv::Mat& processedFrame, const std::vector<cv::Rect>& smileRegions);
};

#endif //TEETH_VISUALISER_H
