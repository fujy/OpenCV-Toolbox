#include "mainwidget.h"
#include "ui/opencvglwidget.h"

#include <QDebug>
#include <QFileDialog>
#include <QGridLayout>
#include <QList>
#include <QMdiArea>
#include <QSignalMapper>
#include <QMdiSubWindow>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    //    openCVGLWidgetList = new QList<OpenCVGLWidget*>();
    //    OpenCVGLWidget* openCVGLWidget1 = new OpenCVGLWidget();
    //    OpenCVGLWidget* openCVGLWidget2 = new OpenCVGLWidget();
    //    openCVGLWidgetList->append(openCVGLWidget1);
    //    openCVGLWidgetList->append(openCVGLWidget2);

    //    originalImageWidget = openCVGLWidget1;
    gridLayout = new QGridLayout(this);

    //    gridLayout->addWidget(openCVGLWidget1, 1, 0);
    //    gridLayout->addWidget(openCVGLWidget2, 1, 1);

    mdiArea = new QMdiArea;
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    //    connect(mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)),this, SLOT(updateMenus()));

    //    windowMapper = new QSignalMapper(this);
    //    connect(windowMapper, SIGNAL(mapped(QWidget*)),this, SLOT(setActiveSubWindow(QWidget*)));

    gridLayout->addWidget(mdiArea, 0,0);
}

MainWidget::~MainWidget()
{

}

void MainWidget::newFromCurrentImageMdi()
{
    OpenCVGLWidget* current = ActiveMdiChild();

    if(current != 0)
    {
        cv::Mat currentImage = current->MOrigianlImage();
        cv::Mat image = currentImage;
        OpenCVGLWidget *openCVGLWidget = createMdiChild();
        openCVGLWidget->SetMOrigianlImage(image);
        openCVGLWidget->showImage(image);
        openCVGLWidget->show();
    }


}

void MainWidget::createNewImageMdi()
{
    QString path = QFileDialog::getOpenFileName(
                this,
                tr("Pick a File"),
                "/home",
                tr("Images ( * .png * .jpg)"));

    if(path.isEmpty())
        return;

    cv::Mat image = cv::imread(path.toStdString());

    OpenCVGLWidget *openCVGLWidget = createMdiChild();
    openCVGLWidget->SetMOrigianlImage(image);
    openCVGLWidget->showImage(image);
    openCVGLWidget->show();
}


void MainWidget::createNewCameraMdi()
{
    OpenCVGLWidget *openCVGLWidget =  createMdiChild();
    openCVGLWidget->show();
    openCVGLWidget->initializeVideoCapure();
}

OpenCVGLWidget* MainWidget::createMdiChild()
{
    OpenCVGLWidget *openCVGLWidget = new OpenCVGLWidget();
    openCVGLWidget->setMinimumHeight(300);
    openCVGLWidget->setMinimumWidth(300);
    mdiArea->addSubWindow(openCVGLWidget);

    return openCVGLWidget;
}

OpenCVGLWidget* MainWidget::ActiveMdiChild()
{
    if (QMdiSubWindow *activeSubWindow = mdiArea->activeSubWindow())
        return qobject_cast<OpenCVGLWidget *>(activeSubWindow->widget());
    return 0;
}


