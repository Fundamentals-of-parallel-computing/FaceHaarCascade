#ifndef HAARCASCADEDETECTOR_H
#define HAARCASCADEDETECTOR_H

#include <opencv2/opencv.hpp>

struct HaarCascadeDetector {
    cv::CascadeClassifier faceCascade;
    cv::CascadeClassifier eyeCascade;
    cv::CascadeClassifier smileCascade;

    bool initialize();

    void processFrame(cv::Mat& inputFrame);
};

#endif  // HAARCASCADEDETECTOR_H
