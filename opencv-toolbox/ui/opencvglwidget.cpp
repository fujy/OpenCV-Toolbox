#include "opencvglwidget.h"
#include "command/acommand.h"

#include <QGLWidget>

#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>
#include <QImage>
#include <QList>
#include <QColor>

OpenCVGLWidget::OpenCVGLWidget(QWidget *parent) : QOpenGLWidget(parent)
{
    mSceneChanged = false;
    mBgColor = QColor::fromRgb(150, 150, 150);

    mOutH = 0;
    mOutW = 0;
    mImgratio = 4.0f/3.0f; // Default image ratio

    mPosX = 0;
    mPosY = 0;
}

OpenCVGLWidget::~OpenCVGLWidget()
{
    if(!timerId)
        killTimer(timerId);

    if(capture.isOpened())
        capture.release();
}

void OpenCVGLWidget::initializeGL()
{
    makeCurrent();
    initializeOpenGLFunctions();
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

    QColor darker = mBgColor.darker();
    f->glClearColor(darker.red(),darker.green(),darker.blue(),darker.alpha());
}

void OpenCVGLWidget::resizeGL(int width, int height)
{
    makeCurrent();
    glViewport(0, 0, (GLint)width, (GLint)height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, width, 0, height, 0, 1); // To Draw image in the center of the area

    glMatrixMode(GL_MODELVIEW);

    // ---> Scaled Image Sizes
    mOutH = width/mImgratio;
    mOutW = width;

    if(mOutH>height)
    {
        mOutW = height*mImgratio;
        mOutH = height;
    }

    emit imageSizeChanged( mOutW, mOutH );
    // < --- Scaled Image Sizes

    mPosX = (width-mOutW)/2;
    mPosY = (height-mOutH)/2;

    mSceneChanged = true;

    updateScene();
}


void OpenCVGLWidget::updateScene()
{
    if( mSceneChanged && this->isVisible() )
        update();
}

void OpenCVGLWidget::paintGL()
{
    makeCurrent();

    if( !mSceneChanged )
        return;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    renderImage();

    mSceneChanged = false;
}

void OpenCVGLWidget::renderImage()
{
    makeCurrent();

    glClear(GL_COLOR_BUFFER_BIT);
    if (!mRenderQtImg.isNull())
    {
        glLoadIdentity();

        QImage image; // the image rendered

        glPushMatrix();
        {
            int imW = mRenderQtImg.width();
            int imH = mRenderQtImg.height();

            // The image is to be resized to fit the widget?
            if( imW != this->size().width() &&
                    imH != this->size().height() )
            {

                image = mRenderQtImg.scaled( //this->size(),
                                             QSize(mOutW,mOutH),
                                             Qt::IgnoreAspectRatio,
                                             Qt::SmoothTransformation
                                             );

                //qDebug( QString( "Image size: (%1x%2)").arg(imW).arg(imH).toAscii() );
            }
            else
                image = mRenderQtImg;

            // --->Centering image in draw area

            glRasterPos2i( mPosX, mPosY );
            // < --- Centering image in draw area

            imW = image.width();
            imH = image.height();

            glDrawPixels( imW, imH, GL_RGBA, GL_UNSIGNED_BYTE, image.bits());
        }
        glPopMatrix();

        // end
        glFlush();
    }
}

bool OpenCVGLWidget::showImage( cv::Mat image )
{
    image.copyTo(mCurrentImage);

    mImgratio = (float)image.cols/(float)image.rows;

    if( mCurrentImage.channels() == 3)
        mRenderQtImg = QImage((const unsigned char*)(mCurrentImage.data),
                              mCurrentImage.cols, mCurrentImage.rows,
                              mCurrentImage.step, QImage::Format_RGB888).rgbSwapped();
    else if( mCurrentImage.channels() == 1)
        mRenderQtImg = QImage((const unsigned char*)(mCurrentImage.data),
                              mCurrentImage.cols, mCurrentImage.rows,
                              mCurrentImage.step, QImage::Format_Indexed8);
    else
        return false;

    mRenderQtImg = QGLWidget::convertToGLFormat(mRenderQtImg);

    mSceneChanged = true;

    updateScene();

    return true;
}

void OpenCVGLWidget::SetMOrigianlImage(cv::Mat image)
{
    image.copyTo(mOrigianlImage);
}

cv::Mat OpenCVGLWidget::MCurrentImage()
{
    return mCurrentImage;
}

cv::Mat OpenCVGLWidget::MOrigianlImage()
{
    return mOrigianlImage;
}

void OpenCVGLWidget::initializeVideoCapure()
{
    capture.open(0);

    if(!capture.isOpened())
        qDebug() << "No camera detected";

    this->timerId = startTimer(50);
}

void OpenCVGLWidget::timerEvent(QTimerEvent *)
{
    bool bSuccess = capture.read(mCurrentImage);

    if (!bSuccess)
    {
        qDebug() << "Cannot read the frame from video file";
        //        killTimer(this);
    }

    this->showImage(mCurrentImage);

    cv::Mat currentImage = this->MCurrentImage();
    foreach ( ACommand* command, commandList) {
        command->execute(currentImage);
    }

}

void OpenCVGLWidget::addCommand(ACommand* command)
{
    cv::Mat currentImage = this->MCurrentImage();
    command->execute(currentImage);
    this->showImage(currentImage);
    this->commandList.append(command);
}
