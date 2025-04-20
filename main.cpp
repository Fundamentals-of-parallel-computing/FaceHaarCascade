#include <iostream>
#include <opencv2/opencv.hpp>

#include "haarcascadedetector.h"

int main() {
    HaarCascadeDetector detector;

    if (!detector.initialize()) {
        return -1;
    }

    cv::VideoCapture videoCapture("../../video.mp4");
    if (!videoCapture.isOpened()) {
        std::cerr << "[Ошибка] Не удалось открыть видеофайл." << std::endl;
        return -1;
    }

    cv::namedWindow("Обнаружение лиц", cv::WINDOW_NORMAL);
    cv::setWindowProperty(
        "Обнаружение лиц", cv::WND_PROP_FULLSCREEN, cv::WINDOW_FULLSCREEN);

    cv::Mat frame;
    while (videoCapture.read(frame)) {
        if (frame.empty()) {
            std::cerr << "[Предупреждение] Пустой кадр, завершение."
                      << std::endl;
            break;
        }

        detector.processFrame(frame);

        cv::imshow("Обнаружение лиц", frame);
        if (cv::waitKey(30) >= 0) break;
    }

    videoCapture.release();
    cv::destroyAllWindows();

    return 0;
}
