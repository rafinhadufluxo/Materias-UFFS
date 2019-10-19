#include <QtGui/QApplication>
#include <QString>
#include "mainwindow.h"
#include "secundarywindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();
    w.raise();
    w.show();
    return a.exec();
}
