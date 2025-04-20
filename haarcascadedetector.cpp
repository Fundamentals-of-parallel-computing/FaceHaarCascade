#include "haarcascadedetector.h"

bool HaarCascadeDetector::initialize() {
    if (!faceCascade.load("../../haarcascade_frontalface_default.xml") ||
        !eyeCascade.load("../../haarcascade_eye.xml") ||
        !smileCascade.load("../../haarcascade_smile.xml")) {
        std::cerr << "[Ошибка] Не удалось загрузить каскады Haar." << std::endl;
        return false;
    }
    return true;
}

void HaarCascadeDetector::processFrame(cv::Mat& inputFrame) {
    cv::Mat grayFrame;
    cv::cvtColor(inputFrame, grayFrame, cv::COLOR_BGR2GRAY);
    cv::equalizeHist(grayFrame, grayFrame);
    cv::GaussianBlur(grayFrame, grayFrame, cv::Size(5, 5), 0);

    std::vector<cv::Rect> faces;
    faceCascade.detectMultiScale(
        grayFrame, faces, 1.1, 5, 0, cv::Size(150, 150));

    for (const auto& faceRect : faces) {
        cv::rectangle(inputFrame, faceRect, cv::Scalar(255, 0, 0), 2);

        cv::Mat faceGray  = grayFrame(faceRect);
        cv::Mat faceColor = inputFrame(faceRect);

        std::vector<cv::Rect> eyes;
        eyeCascade.detectMultiScale(
            faceGray, eyes, 1.1, 10, 0, cv::Size(50, 50));
        for (const auto& eyeRect : eyes) {
            cv::rectangle(faceColor, eyeRect, cv::Scalar(0, 255, 0), 2);
        }

        std::vector<cv::Rect> smiles;
        smileCascade.detectMultiScale(
            faceGray, smiles, 1.24, 15, 0, cv::Size(40, 40));
        for (const auto& smileRect : smiles) {
            cv::rectangle(faceColor, smileRect, cv::Scalar(0, 0, 255), 2);
        }
    }
}
