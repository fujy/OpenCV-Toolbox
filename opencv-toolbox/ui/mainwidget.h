#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <ui/opencvglwidget.h>

#include <QWidget>
#include <QTimer>

class QGridLayout;
class QHBoxLayout;
class QListView;
class QMdiArea;
class QSignalMapper;

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

    OpenCVGLWidget* ActiveMdiChild();
    OpenCVGLWidget* createMdiChild();

    void newFromCurrentImageMdi();
    void createNewImageMdi();
    void createNewCameraMdi();

signals:

public slots:

private:
    QGridLayout* gridLayout;
    QHBoxLayout* hboxLayout;
    QList<OpenCVGLWidget*>* openCVGLWidgetList;
    QListView* listView;
    OpenCVGLWidget* activeImageMdi;

    QMdiArea *mdiArea;
    QSignalMapper *windowMapper;


};

#endif // MAINWIDGET_H
