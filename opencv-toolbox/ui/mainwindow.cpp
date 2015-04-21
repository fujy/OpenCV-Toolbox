#include "mainwindow.h"
#include "control/saltandpeppernoisecontroller.h"

#include "command/bgrtograycommand.h"
#include "command/bgrtohsvcommand.h"
#include "command/bgrtoluvcommand.h"
#include "command/cannycommand.h"
#include "command/fastcommand.h"
#include "command/flipcommand.h"
#include "command/gaussianblurcommand.h"
#include "command/hsvtobgrcommand.h"
#include "command/laplaciancommand.h"
#include "command/meanblurcommand.h"
#include "command/medianblurcommand.h"
#include "command/morphclosecommand.h"
#include "command/morphdilatecommand.h"
#include "command/morpherodecommand.h"
#include "command/morphopencommand.h"
#include "command/peppernoisecommand.h"
#include "command/saltnoisecommand.h"
#include "command/sharpen2dcommand.h"
#include "command/siftcommand.h"
#include "command/sobelxcommand.h"
#include "command/sobelycommand.h"
#include "command/surfcommand.h"

#include <iostream>
#include <stdio.h>
#include "opencv2/core.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/core/ocl.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/calib3d.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/xfeatures2d.hpp"

#include <QAction>
#include <QDebug>
#include <QFileDialog>
#include <QInputDialog>
#include <QMenuBar>
#include <QContextMenuEvent>
#include <QStatusBar>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setWindowTitle(tr("OpenCV Toolbox"));
    resize(width, height);

    mainWidget = new MainWidget();
    setCentralWidget(mainWidget);

    createActions();
    createMenus();

    QString message = tr("Ready");
    statusBar()->showMessage(message);
}

MainWindow::~MainWindow()
{
}

void MainWindow::createActions()
{
    newImageAct = new QAction(tr("&New Image"), this);
    newImageAct->setShortcuts(QKeySequence::New);
    newImageAct->setStatusTip(tr("Create a new file"));
    connect(newImageAct, SIGNAL(triggered()), this, SLOT(newImage()));

    openImageAct = new QAction(tr("&Open Image..."), this);
    openImageAct->setShortcuts(QKeySequence::Open);
    openImageAct->setStatusTip(tr("Open an existing file"));
    connect(openImageAct, SIGNAL(triggered()), this, SLOT(openImage()));

    openCameraAct = new QAction(tr("&Open Camera..."), this);
    connect(openCameraAct, SIGNAL(triggered()), this, SLOT(openCamera()));

    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(saveImage()));

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    flipAct = new QAction(tr("&Flip"), this);
    connect(flipAct, SIGNAL(triggered()), this, SLOT(flip()));

    undoAct = new QAction(tr("&Undo"), this);
    undoAct->setShortcuts(QKeySequence::Undo);
    undoAct->setStatusTip(tr("Undo the last operation"));
    connect(undoAct, SIGNAL(triggered()), this, SLOT(undo()));

    redoAct = new QAction(tr("&Redo"), this);
    redoAct->setShortcuts(QKeySequence::Redo);
    redoAct->setStatusTip(tr("Redo the last operation"));
    connect(redoAct, SIGNAL(triggered()), this, SLOT(redo()));


    saltAct = new QAction(tr("&Add Salt And Pepper Noise"), this);
    connect(saltAct, SIGNAL(triggered()), this, SLOT(salt()));



    rgbToHsvAct = new QAction(tr("&RGB To HSV"), this);
    connect(rgbToHsvAct, SIGNAL(triggered()), this, SLOT(bgrToHsv()));

    hsvToRgbAct = new QAction(tr("&HSV To RGB"), this);
    connect(hsvToRgbAct, SIGNAL(triggered()), this, SLOT(hsvToBgr()));

    rgbToGrayAct = new QAction(tr("&RGB To Gray"), this);
    connect(rgbToGrayAct, SIGNAL(triggered()), this, SLOT(bgrToGray()));

    bgrToLuvAct = new QAction(tr("&RGB To LUV"), this);
    connect(bgrToLuvAct, SIGNAL(triggered()), this, SLOT(bgrToLuv()));


    morphDilateAct = new QAction(tr("&Dilate"), this);
    connect(morphDilateAct, SIGNAL(triggered()), this, SLOT(morphDilate()));

    morphErodeAct = new QAction(tr("&Erode"), this);
    connect(morphErodeAct, SIGNAL(triggered()), this, SLOT(morphErode()));

    morphOpenAct = new QAction(tr("&Open"), this);
    connect(morphOpenAct, SIGNAL(triggered()), this, SLOT(morphOpen()));

    morphCloseAct = new QAction(tr("&Close"), this);
    connect(morphCloseAct, SIGNAL(triggered()), this, SLOT(morphClose()));

    meanBlurAct = new QAction(tr("&Mean Blur"), this);
    connect(meanBlurAct, SIGNAL(triggered()), this, SLOT(meanBlur()));

    medianBlurAct = new QAction(tr("&Median Blur"), this);
    connect(medianBlurAct, SIGNAL(triggered()), this, SLOT(medianBlur()));

    gaussianBlurAct = new QAction(tr("&Gaussian Blur"), this);
    connect(gaussianBlurAct, SIGNAL(triggered()), this, SLOT(gaussianBlur()));

    sharpen2DAct= new QAction(tr("&Sharpen"), this);
    connect(sharpen2DAct, SIGNAL(triggered()), this, SLOT(sharpen2D()));

    sobelXAct = new QAction(tr("&Sobel X"), this);
    connect(sobelXAct, SIGNAL(triggered()), this, SLOT(sobelX()));

    sobelYAct = new QAction(tr("&Sobel Y"), this);
    connect(sobelYAct, SIGNAL(triggered()), this, SLOT(sobelY()));

    laplacianAct= new QAction(tr("&Laplacian"), this);
    connect(laplacianAct, SIGNAL(triggered()), this, SLOT(laplacian()));

    cannyAct= new QAction(tr("&Canny"), this);
    connect(cannyAct, SIGNAL(triggered()), this, SLOT(canny()));

    fastAct= new QAction(tr("&FAST"), this);
    connect(fastAct, SIGNAL(triggered()), this, SLOT(fast()));

    surfAct= new QAction(tr("&SURF"), this);
    connect(surfAct, SIGNAL(triggered()), this, SLOT(surf()));

    siftAct= new QAction(tr("&SIFT"), this);
    connect(siftAct, SIGNAL(triggered()), this, SLOT(sift()));

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAct, SIGNAL(triggered()), this, SLOT(aboutQt()));

}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newImageAct);
    fileMenu->addAction(openImageAct);
    fileMenu->addAction(openCameraAct);
    fileMenu->addAction(saveAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(flipAct);

    filterMenu = menuBar()->addMenu(tr("&Filter"));
    filterMenu->addAction(meanBlurAct);
    filterMenu->addAction(medianBlurAct);
    filterMenu->addAction(gaussianBlurAct);

    noiseMenu = menuBar()->addMenu(tr("&Noise"));
    noiseMenu->addAction(saltAct);

    colorSpaceMenu = menuBar()->addMenu(tr("&Color Space"));
    colorSpaceMenu->addAction(rgbToHsvAct);
    colorSpaceMenu->addAction(hsvToRgbAct);
    colorSpaceMenu->addAction(rgbToGrayAct);
    colorSpaceMenu->addAction(bgrToLuvAct);

    morphologicalOperationsMenu = menuBar()->addMenu(tr("&Morphological Operations"));
    morphologicalOperationsMenu->addAction(morphDilateAct);
    morphologicalOperationsMenu->addAction(morphErodeAct);
    morphologicalOperationsMenu->addAction(morphOpenAct);
    morphologicalOperationsMenu->addAction(morphCloseAct);

    edgeDetectionMenu = menuBar()->addMenu(tr("&Edge Detection"));
    edgeDetectionMenu->addAction(sobelXAct);
    edgeDetectionMenu->addAction(sobelYAct);
    edgeDetectionMenu->addAction(laplacianAct);
    edgeDetectionMenu->addAction(sharpen2DAct);
    edgeDetectionMenu->addAction(cannyAct);

    featuresMenu = menuBar()->addMenu(tr("&Features"));
    featuresMenu->addAction(fastAct);
    featuresMenu->addAction(surfAct);
    featuresMenu->addAction(siftAct);


    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);


    formatMenu = filterMenu->addMenu(tr("&Format"));
}

void MainWindow::newImage()
{
    mainWidget->newFromCurrentImageMdi();
}

void MainWindow::openImage()
{
    mainWidget->createNewImageMdi();
}

void MainWindow::saveImage()
{
    OpenCVGLWidget* current = mainWidget->ActiveMdiChild();
    if(current != 0)
    {
        QString savedImagePath = QFileDialog::getSaveFileName(
                this,
                tr("Save Image"),
                QDir::currentPath(),
                tr("Image (*.png,*.jpeg,*.jpg,*.bmp)") );

        if (!savedImagePath.isNull()) {
            cv::Mat currentImage = current->MCurrentImage();
            cv::imwrite(savedImagePath.toStdString(), currentImage);
        }
    }
}

void MainWindow::openCamera()
{
    mainWidget->createNewCameraMdi();
}


void MainWindow::undo()
{

}

void MainWindow::redo()
{

}

void MainWindow::flip()
{
    OpenCVGLWidget* current = mainWidget->ActiveMdiChild();
    if(current != 0)
    {
        current->addCommand(new FlipCommand);
    }
}

void MainWindow::salt()
{
    OpenCVGLWidget* current = mainWidget->ActiveMdiChild();
    if(current != 0)
    {
        current->addCommand(new SaltNoiseCommand);
    }
}

void MainWindow::bgrToHsv()
{
    OpenCVGLWidget* current = mainWidget->ActiveMdiChild();
    if(current != 0)
    {
        current->addCommand(new BGRToHSVCommand);
    }
}

void MainWindow::hsvToBgr()
{
    OpenCVGLWidget* current = mainWidget->ActiveMdiChild();
    if(current != 0)
    {
        current->addCommand(new HSVToBGRCommand);
    }
}

void MainWindow::bgrToGray()
{
    OpenCVGLWidget* current = mainWidget->ActiveMdiChild();
    if(current != 0)
    {
        current->addCommand(new BGRToGrayCommand);
    }
}

void MainWindow::bgrToLuv()
{
    OpenCVGLWidget* current = mainWidget->ActiveMdiChild();
    if(current != 0)
    {
        current->addCommand(new BGRToLUVCommand);
    }
}

void MainWindow::morphDilate()
{
    OpenCVGLWidget* current = mainWidget->ActiveMdiChild();
    if(current != 0)
    {
        current->addCommand(new MorphDilateCommand);
    }
}

void MainWindow::morphErode()
{
    OpenCVGLWidget* current = mainWidget->ActiveMdiChild();
    if(current != 0)
    {
        current->addCommand(new MorphErodeCommand);
    }
}

void MainWindow::morphOpen()
{
    OpenCVGLWidget* current = mainWidget->ActiveMdiChild();
    if(current != 0)
    {
        current->addCommand(new MorphOpenCommand);
    }
}

void MainWindow::morphClose()
{
    OpenCVGLWidget* current = mainWidget->ActiveMdiChild();
    if(current != 0)
    {
        current->addCommand(new MorphCloseCommand);
    }
}

void MainWindow::meanBlur()
{
    OpenCVGLWidget* current = mainWidget->ActiveMdiChild();
    if(current != 0)
    {
        current->addCommand(new MeanBlurCommand);
    }
}

void MainWindow::medianBlur()
{
    OpenCVGLWidget* current = mainWidget->ActiveMdiChild();
    if(current != 0)
    {
        current->addCommand(new MedianBlurCommand);
    }
}

void MainWindow::gaussianBlur()
{
    OpenCVGLWidget* current = mainWidget->ActiveMdiChild();
    if(current != 0)
    {
        current->addCommand(new GaussianBlurCommand);
    }
}

void MainWindow::sobelX()
{
    OpenCVGLWidget* current = mainWidget->ActiveMdiChild();
    if(current != 0)
    {
        current->addCommand(new SobelXCommand);
    }
}

void MainWindow::sobelY()
{
    OpenCVGLWidget* current = mainWidget->ActiveMdiChild();
    if(current != 0)
    {
        current->addCommand(new SobelYCommand);
    }
}

void MainWindow::laplacian()
{
    OpenCVGLWidget* current = mainWidget->ActiveMdiChild();
    if(current != 0)
    {
        current->addCommand(new LaplacianCommand);
    }
}

void MainWindow::sharpen2D()
{
    OpenCVGLWidget* current = mainWidget->ActiveMdiChild();
    if(current != 0)
    {
        current->addCommand(new Sharpen2DCommand);
    }
}

void MainWindow::canny()
{
    OpenCVGLWidget* current = mainWidget->ActiveMdiChild();
    if(current != 0)
    {
        current->addCommand(new CannyCommand);
    }
}

void MainWindow::fast()
{
    OpenCVGLWidget* current = mainWidget->ActiveMdiChild();
    if(current != 0)
    {
        current->addCommand(new FASTCommand);
    }

}

void MainWindow::surf()
{
    OpenCVGLWidget* current = mainWidget->ActiveMdiChild();
    if(current != 0)
    {
        current->addCommand(new SURFCommand);
    }
}

void MainWindow::sift()
{
    OpenCVGLWidget* current = mainWidget->ActiveMdiChild();
    if(current != 0)
    {
        current->addCommand(new SIFTCommand);
    }
}

void MainWindow::about()
{

}

void MainWindow::aboutQt()
{

}
