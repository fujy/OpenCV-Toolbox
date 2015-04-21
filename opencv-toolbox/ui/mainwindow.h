#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui/mainwidget.h"

#include <QMainWindow>

class QActionGroup;
class QAction;
class QContextMenuEvent;
class QMenu;
class QVBoxLayout;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    static const int width = 1024;
    static const int height = 600;

    cv::VideoCapture mCapture;

    MainWidget *mainWidget;

    QMenu *fileMenu;
    QMenu *formatMenu;
    QAction *openImageAct;
    QAction *newImageAct;
    QAction *openCameraAct;
    QAction *saveAct;
    QAction *exitAct;
    QAction *undoAct;
    QAction *redoAct;

    QMenu *editMenu;
    QAction *flipAct;

    QMenu *noiseMenu;
    QAction *saltAct;

    QMenu *colorSpaceMenu;
    QAction *rgbToHsvAct;
    QAction *hsvToRgbAct;
    QAction *rgbToGrayAct;
    QAction *bgrToLuvAct;

    QMenu *morphologicalOperationsMenu;
    QAction *morphDilateAct;
    QAction *morphErodeAct;
    QAction *morphOpenAct;
    QAction *morphCloseAct;

    QMenu *filterMenu;
    QAction *meanBlurAct;
    QAction *medianBlurAct;
    QAction *gaussianBlurAct;
    QAction *sharpen2DAct;

    QMenu *edgeDetectionMenu;
    QAction *sobelXAct;
    QAction *sobelYAct;
    QAction *laplacianAct;
    QAction *cannyAct;

    QMenu *featuresMenu;
    QAction *fastAct;
    QAction *surfAct;
    QAction *siftAct;

    QMenu *helpMenu;
    QAction *aboutAct;
    QAction *aboutQtAct;

    // convert to tab if times allowed
    //QTabWidget* tabWidget;

    QVBoxLayout* layout;

    void createActions();
    void createMenus();

private slots:
    void newImage();
    void openImage();
    void openCamera();
    void saveImage();
    void undo();
    void redo();

    void flip();

    void salt();

    void bgrToHsv();
    void hsvToBgr();
    void bgrToGray();
    void bgrToLuv();

    void morphDilate();
    void morphErode();
    void morphOpen();
    void morphClose();
    void sharpen2D();

    void meanBlur();
    void medianBlur();
    void gaussianBlur();

    void sobelX();
    void sobelY();
    void laplacian();
    void canny();

    void fast();
    void surf();
    void sift();

    void about();
    void aboutQt();

};

#endif // MAINWINDOW_H
