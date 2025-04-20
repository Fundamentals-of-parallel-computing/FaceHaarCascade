TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += /usr/include/opencv4

LIBS += -lopencv_core \
        -lopencv_imgproc \
        -lopencv_highgui \
        -lopencv_imgcodecs \
        -lopencv_features2d \
        -lopencv_calib3d \
        -lopencv_objdetect \
        -lopencv_videoio

SOURCES += \
    haarcascadedetector.cpp \
    main.cpp

DISTFILES += \
    haarcascade_eye.xml \
    haarcascade_frontalface_default.xml \
    haarcascade_profileface.xml \
    haarcascade_smile.xml \
    image.png \
    video.mp4

HEADERS += \
    haarcascadedetector.h
