#ifndef SECUNDARYWINDOW_H
#define SECUNDARYWINDOW_H

#include "mainwindow.h"
#include <QMainWindow>

namespace Ui {
    class SecundaryWindow;
}

class SecundaryWindow : public QMainWindow
{
    Q_OBJECT
public:
    SecundaryWindow(QWidget *parent = 0, Ui::MainWindow *ui = 0, QImage *selectedImage = 0, QImage *targetImg = 0);
    ~SecundaryWindow();
    Ui::SecundaryWindow *effect;
    Ui::MainWindow *main;
    QImage *selected, *target;

protected:
    void changeEvent(QEvent *e);

signals:

public slots:
    void applyChanges(void);
    void changeR(void);
    void changeG(void);
    void changeB(void);
    void changeBrightness(void);

private:

};

#endif // SECUNDARYWINDOW_H
