#include "Visualiser.h"

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

void Visualiser::renderVisuals(const cv::Mat &processedFrame, const std::vector<cv::Rect> &smileRegions) {
    cv::Mat displayFrame;
    cv::cvtColor(processedFrame, displayFrame, cv::COLOR_GRAY2BGR);
    // TODO: Replace with actual veneer overlay logic (png, etc.)
    for(const auto& smile: smileRegions) {
        int newWidth = static_cast<int>(smile.width * 0.6);
        int newHeight = static_cast<int>(smile.height * 0.4);
        int newX = smile.x + (smile.width - newWidth) / 2;
        int newY = smile.y + (smile.height - newHeight) / 2 + static_cast<int>(smile.height * 0.1);
        cv::Rect teethRect(newX, newY, newWidth, newHeight);

        cv::rectangle(displayFrame, teethRect, cv::Scalar(0, 255, 0), 2);

        cv::Mat veneerOverlay = displayFrame(teethRect).clone();
        cv::Mat white(veneerOverlay.size(), veneerOverlay.type(), cv::Scalar(255, 255, 255));
        double alpha = 0.4;
        cv::addWeighted(white, alpha, veneerOverlay, 1.0 - alpha, 0.0, veneerOverlay);
        veneerOverlay.copyTo(displayFrame(teethRect));
    }
    cv::imshow("Smile Simulator", displayFrame);
}
