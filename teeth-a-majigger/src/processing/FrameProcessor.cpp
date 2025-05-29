#include "FrameProcessor.h"

FrameProcessor::FrameProcessor() {
    imgOrig = cv::Mat(frameHeight, frameWidth, CV_8UC3);
    imgGrey = cv::Mat(frameHeight, frameWidth, CV_8UC1);
}

cv::Mat FrameProcessor::preprocess(const cv::Mat &rawFrame) {
    cv::resize(rawFrame, imgOrig, cv::Size(frameWidth, frameHeight));
    cv::cvtColor(imgOrig, imgGrey, cv::COLOR_BGR2GRAY);
    cv::equalizeHist(imgGrey, imgGrey);
    return imgGrey;
}
