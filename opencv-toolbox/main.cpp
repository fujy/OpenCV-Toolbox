#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include <QRegExp>
#include <QDebug>

#include "ui/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTranslator qtTranslator;
    qtTranslator.load("qt_" + QLocale::system().name(),
                      QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&qtTranslator);

    QTranslator myappTranslator;
    myappTranslator.load("myapp_" + QLocale::system().name());
    app.installTranslator(&myappTranslator);

    MainWindow mainWindow;
    mainWindow.show();

//    QRegExp rx("^([a-z]+|[A-Z]+):(-?)([0-9]+|[0-9]+.[0-9]+)$");
//    QString s("abc:5.5");
//    qDebug() << rx.indexIn(s);

    return app.exec();
}
