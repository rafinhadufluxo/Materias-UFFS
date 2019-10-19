#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;
    QImage *selectedImage, *targetImg;

protected:
    void changeEvent(QEvent *e);

public slots:
    void openFile(void);
    void applyChanges(void);
    void saveFile(void);
    void exit(void);
    void effects(void);

    void zoom(void);
    void resize(void);
    void crop(void);
    void rotateRight(void);
    void rotateLeft(void);
    void mirror(void);
    void reflection(void);
    void grayScale(void);
    void xray(void);
    void sepia(void);

private:
    void simpleResize(int w2, int h2);
    void bilinearResize(int w2, int h2);
    void bicubicResize(int w2, int h2);
    void simpleCrop(int x1, int y1, int x2, int y2);
};

#endif // MAINWINDOW_H
