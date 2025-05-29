#include "SmileDetector.h"
#include "FileUtil.h"

SmileDetector::SmileDetector() {
    std::filesystem::path assetsPath = FileUtil::getAssetsPath();
    if (!faceCascade.load((assetsPath / "haarcascade_frontalface_default.xml").string())) {
        throw std::runtime_error("Could not load face cascade classifier");
    }
    if (!smileCascade.load((assetsPath / "haarcascade_smile.xml").string())) {
        throw std::runtime_error("Could not load smile cascade classifier");
    }
}

std::vector <cv::Rect> SmileDetector::detectSmiles(const cv::Mat &frame) {
    std::vector<cv::Rect> faces, smiles;
    faceCascade.detectMultiScale(frame, faces, 1.1, 3, 0, cv::Size(80, 80));

    for(const auto &face: faces){
        cv::Mat faceROI = frame(face);
        std::vector<cv::Rect> detectedSmiles;
        smileCascade.detectMultiScale(faceROI, detectedSmiles, 1.7, 22, 0, cv::Size(25, 25));
        for(auto &smile: detectedSmiles) {
            cv::Rect smileRect(smile.x + face.x, smile.y + face.y, smile.width, smile.height);
            smiles.push_back(smileRect);
        }
    }
    return smiles;
}
