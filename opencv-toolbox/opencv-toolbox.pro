#-------------------------------------------------
#
# Project created by QtCreator 2015-04-20T05:13:06
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = opencv-example3
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += /usr/local/include/opencv2
LIBS += -L/usr/local/lib
LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_imgcodecs
LIBS += -lopencv_highgui
LIBS += -lopencv_ml
LIBS += -lopencv_video
LIBS += -lopencv_videoio
LIBS += -lopencv_features2d
LIBS += -lopencv_calib3d
LIBS += -lopencv_objdetect
LIBS += -lopencv_contrib
LIBS += -lopencv_legacy
LIBS += -lopencv_flann
LIBS += -lopencv_xfeatures2d
#LIBS += -lopencv_nonfree

SOURCES += main.cpp \
    ui/mainwindow.cpp \
    ui/mainwidget.cpp \
    model/image.cpp \
    ui/opencvglwidget.cpp \
    control/saltandpeppernoisecontroller.cpp \
    model/properties.cpp \
    command/acommand.cpp \
    command/flipcommand.cpp \
    command/bgrtograycommand.cpp \
    command/bgrtohsvcommand.cpp \
    command/bgrtoluvcommand.cpp \
    command/cannycommand.cpp \
    command/fastcommand.cpp \
    command/gaussianblurcommand.cpp \
    command/laplaciancommand.cpp \
    command/meanblurcommand.cpp \
    command/medianblurcommand.cpp \
    command/morphclosecommand.cpp \
    command/morphdilatecommand.cpp \
    command/morpherodecommand.cpp \
    command/morphopencommand.cpp \
    command/saltnoisecommand.cpp \
    command/sharpen2dcommand.cpp \
    command/siftcommand.cpp \
    command/sobelxcommand.cpp \
    command/sobelycommand.cpp \
    command/surfcommand.cpp \
    command/peppernoisecommand.cpp \
    command/hsvtobgrcommand.cpp

HEADERS += \
    ui/mainwindow.h \
    ui/mainwidget.h \
    model/image.h \
    ui/opencvglwidget.h \
    control/saltandpeppernoisecontroller.h \
    model/properties.h \
    command/acommand.h \
    command/flipcommand.h \
    command/bgrtograycommand.h \
    command/bgrtohsvcommand.h \
    command/bgrtoluvcommand.h \
    command/cannycommand.h \
    command/fastcommand.h \
    command/gaussianblurcommand.h \
    command/laplaciancommand.h \
    command/meanblurcommand.h \
    command/medianblurcommand.h \
    command/morphclosecommand.h \
    command/morphdilatecommand.h \
    command/morpherodecommand.h \
    command/morphopencommand.h \
    command/saltnoisecommand.h \
    command/sharpen2dcommand.h \
    command/siftcommand.h \
    command/sobelxcommand.h \
    command/sobelycommand.h \
    command/surfcommand.h \
    command/peppernoisecommand.h \
    command/hsvtobgrcommand.h
