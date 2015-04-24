#ifndef GLWIDGET_H
#define GLWIDGET_H

#include "model/commandlistmodel.h"

#include <opencv2/opencv.hpp>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QList>

class QImage;
class QColor;
//class QList;//forward declration
class ACommand;

class OpenCVGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    OpenCVGLWidget(QWidget *parent = 0);
    ~OpenCVGLWidget();
    cv::Mat MCurrentImage();
    cv::Mat MOrigianlImage();
    void SetMOrigianlImage(cv::Mat image);
    void initializeVideoCapure();
    void addCommand(ACommand* command);
    CommandListModel* getCommandListModel();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    void updateScene(); /// Forces a scene update
    void renderImage(); /// Render image on openGL frame

private:
    bool mSceneChanged; /// Indicates when OpenGL view is to be redrawn

    QImage mRenderQtImg; /// Qt image to be rendered

    cv::Mat mCurrentImage; /// Current OpenCV image to be shown
    cv::Mat mOrigianlImage; /// Current OpenCV image to be shown

    int timerId;
    cv::VideoCapture capture;

    QColor mBgColor; /// Background color

    int mOutH; /// Resized Image height
    int mOutW; /// Resized Image width
    float mImgratio; /// height/width ratio

    int mPosX; /// Top left X position to render image in the center of widget
    int mPosY; /// Top left Y position to render image in the center of widget

//    QList<ACommand*> commandList;
    CommandListModel* commandListModel;

signals:
    void imageSizeChanged( int outW, int outH ); /// Used to resize the image outside the widget

private slots:
    void timerEvent(QTimerEvent *);


public slots:
    bool showImage( cv::Mat image ); /// Used to set the image to be viewed

};

#endif // GLWIDGET_H
