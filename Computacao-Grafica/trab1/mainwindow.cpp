#include "mainwindow.h"
#include "secundarywindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QDebug"
#include <QScrollArea>
#include "math.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    selectedImage = new QImage();

    connect(ui->actionEffects, SIGNAL(triggered()), this, SLOT(effects()));

    connect(ui->actionOpenFile, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(ui->applyButton, SIGNAL(clicked()), this, SLOT(applyChanges()));
    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveFile()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(exit()));

    connect(ui->resizeButton, SIGNAL(clicked()), this, SLOT(resize()));
    connect(ui->resizeSlider, SIGNAL(sliderReleased()), this, SLOT(zoom()));
    connect(ui->cropButton, SIGNAL(clicked()), this, SLOT(crop()));
    connect(ui->rightButton, SIGNAL(clicked()), this, SLOT(rotateRight()));
    connect(ui->leftButton, SIGNAL(clicked()), this, SLOT(rotateLeft()));
    connect(ui->mirrorButton, SIGNAL(clicked()), this, SLOT(mirror()));
    connect(ui->reflectionButton, SIGNAL(clicked()), this, SLOT(reflection()));
    connect(ui->xRayButton, SIGNAL(clicked()), this, SLOT(xray()));
    connect(ui->greyscaleButton, SIGNAL(clicked()), this, SLOT(grayScale()));
    connect(ui->sepiaButton, SIGNAL(clicked()), this, SLOT(sepia()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::effects(void) {
    qDebug() << "Chamou a janela effects";
    targetImg = selectedImage;
    SecundaryWindow *s = new SecundaryWindow(ui->centralWidget, ui, selectedImage, targetImg);
    s->show();
}

void MainWindow::openFile(void)
{
    qDebug() << "Clicou em open file";
    QString path = QFileDialog::getOpenFileName(this, tr("Open image - Image Factory")," ",tr("Image Files (*.png *.jpg *.bmp)"));
    qDebug() << path;
    selectedImage->load(path);

    ui->imgSelected->setPixmap(QPixmap::fromImage(*selectedImage));
    ui->imgResult->setPixmap(QPixmap::fromImage(*selectedImage));

    ui->scrollArea->setBackgroundRole(QPalette::Background);
    ui->scrollArea->setWidget(ui->imgResult);

    ui->imgResult->setGeometry(ui->imgResult->x(), ui->imgResult->y(), selectedImage->width(), selectedImage->height());
}

void MainWindow::exit(void)
{
    qApp->exit(0);
}

void MainWindow::applyChanges(void)
{
    qDebug() << "Salvou a alteracao feita";
    selectedImage = targetImg;
    ui->imgSelected->setPixmap(QPixmap::fromImage(*selectedImage));
}

void MainWindow::saveFile(void)
{
    qDebug() << "Clicou em save";
    QString path = QFileDialog::getSaveFileName(this, tr("Image Factory - Open image")," ",tr("Image Files (*.png *.jpg *.bmp)"));
    qDebug() << path;
    targetImg->save(path);
}

void MainWindow::zoom(void)
{
    double sliderValue = ui->resizeSlider->value()-1;
    int width = selectedImage->width();
    int height = selectedImage->height();

    if(sliderValue < 0){
        sliderValue = (1/sliderValue)*(-1);
        qDebug() << "Foi chamado o magnify de valor" << sliderValue;
        simpleResize(width * sliderValue, height * sliderValue);
    }else if(sliderValue >= 0){
        qDebug() << "Foi chamado o magnify de valor" << sliderValue+2;
        simpleResize(width * (sliderValue + 2), height * (sliderValue + 2));
    }

}

void MainWindow::resize(void)
{
    qDebug() << "Foi chamado o resize:";
    double aspectRatio;
    int newWidth = ui->inputWidth->text().toInt(0);
    int newHeight = ui->inputHeight->text().toInt(0);
    int resizeType = ui->boxResize->currentIndex();

    if(newWidth > 0 && newHeight > 0){
        if(ui->boxAspectRatio->isChecked()){

            aspectRatio = selectedImage->width() / (double)selectedImage->height();
            qDebug() << "   -Com aspect ratio selecionado de" << aspectRatio;


            if(newWidth > newHeight){
                if(resizeType == 1){
                    qDebug() << "   -Algoritmo Bilinear pela altura.";
                    bilinearResize(newHeight*aspectRatio, newHeight);
                }else if(resizeType == 2){
                    qDebug() << "   -Algoritmo Bicubico pela altura.";
                    bicubicResize(newHeight*aspectRatio, newHeight);
                }else{
                    qDebug() << "   -Algoritmo Vizinho proximo pela altura.";
                    simpleResize(newHeight*aspectRatio, newHeight);
                }
            }else{
                if(resizeType == 1){
                    qDebug() << "   -Algoritmo Bilinear pela largura.";
                    bilinearResize(newWidth*aspectRatio, newWidth);
                }else if(resizeType == 2){
                    qDebug() << "   -Algoritmo Bicubico pela largura.";
                    bicubicResize(newWidth*aspectRatio, newWidth);
                }else{
                    qDebug() << "   -Algoritmo Vizinho proximo pela largura.";
                    simpleResize(newWidth*aspectRatio, newWidth);
                }
            }

        }else{
            qDebug() << "   -Sem aspect ratio.";
            if(resizeType == 1){
                qDebug() << "   -Algoritmo Bilinear.";
                bilinearResize(newWidth, newHeight);
            }else if(resizeType == 2){
                qDebug() << "   -Algoritmo Bicubico.";
                bicubicResize(newWidth, newHeight);
            }else{
                qDebug() << "   -Algoritmo Vizinho proximo.";
                simpleResize(newWidth, newHeight);
            }
        }
    }
}

/* Nearest Neighbor Image Scaling */
void MainWindow::simpleResize(int target_width, int target_height)
{
    targetImg = new QImage(target_width, target_height, selectedImage->format());

    double x_ratio = selectedImage->width() / (double)target_width;
    double y_ratio = selectedImage->height() / (double)target_height;
    double x_source, y_source;

    for (int i = 0; i < target_width; i++) {
        for (int j = 0; j < target_height; j++) {

            x_source = floor(i * x_ratio);
            y_source = floor(j * y_ratio);

            QRgb qrgb = selectedImage->pixel(x_source, y_source);
            targetImg->setPixel(i, j, qrgb);
        }
    }

    ui->imgResult->setGeometry(ui->imgResult->x(), ui->imgResult->y(), targetImg->width(), targetImg->height());
    ui->imgResult->setPixmap(QPixmap::fromImage(*targetImg));
}

/* Bilinear Image Scaling */
void MainWindow::bilinearResize(int target_width, int target_height)
{
    targetImg = new QImage(target_width, target_height, selectedImage->format());

    double x_ratio = selectedImage->width() / (double)target_width;
    double y_ratio = selectedImage->height() / (double)target_height;
    double x_source, y_source, red, green, blue;

    QRgb center = qRgb(0, 0, 0);
    QRgb left = qRgb(0, 0, 0);
    QRgb right = qRgb(0, 0, 0);
    QRgb upper = qRgb(0, 0, 0);
    QRgb down = qRgb(0, 0, 0);

    QRgb average = qRgb(0, 0, 0);

    for (int i = 0; i < target_width; i++) {
        for (int j = 0; j < target_height; j++) {

            x_source = floor(i * x_ratio);
            y_source = floor(j * y_ratio);

            center = selectedImage->pixel(x_source, y_source);
            left = selectedImage->pixel(x_source-1, y_source);
            right = selectedImage->pixel(x_source+1, y_source);
            upper = selectedImage->pixel(x_source, y_source-1);
            down = selectedImage->pixel(x_source, y_source+1);

            red = (qRed(left) + qRed(right) + qRed(upper) + qRed(down))/4.0;
            green = (qGreen(left) + qGreen(right) + qGreen(upper) + qGreen(down))/4.0;
            blue = (qBlue(left) + qBlue(right) + qBlue(upper) + qBlue(down))/4.0;

            average = qRgb(red, green, blue);

            targetImg->setPixel(i, j, average);
        }
    }

    ui->imgResult->setGeometry(ui->imgResult->x(), ui->imgResult->y(), targetImg->width(), targetImg->height());
    ui->imgResult->setPixmap(QPixmap::fromImage(*targetImg));
}

/* Bicubic Image Scaling */
void MainWindow::bicubicResize(int target_width, int target_height)
{
    targetImg = new QImage(target_width, target_height, selectedImage->format());

    double x_ratio = selectedImage->width() / (double)target_width;
    double y_ratio = selectedImage->height() / (double)target_height;
    double x_source, y_source, red, green, blue;

    QRgb leftUpper = qRgb(0, 0, 0);
    QRgb upper = qRgb(0, 0, 0);
    QRgb rightupper = qRgb(0, 0, 0);
    QRgb left = qRgb(0, 0, 0);

    QRgb center = qRgb(0, 0, 0);

    QRgb right = qRgb(0, 0, 0);
    QRgb leftDown = qRgb(0, 0, 0);
    QRgb down = qRgb(0, 0, 0);
    QRgb rightDown = qRgb(0, 0, 0);
    QRgb average = qRgb(0, 0, 0);

    for (int i = 0; i < target_width; i++) {
        for (int j = 0; j < target_height; j++) {

            x_source = floor(i * x_ratio);
            y_source = floor(j * y_ratio);

            leftUpper = selectedImage->pixel(x_source-1, y_source-1);
            upper = selectedImage->pixel(x_source, y_source-1);
            rightupper = selectedImage->pixel(x_source+1, y_source-1);
            left = selectedImage->pixel(x_source-1, y_source);

            center = selectedImage->pixel(x_source, y_source);

            right = selectedImage->pixel(x_source+1, y_source);
            leftDown = selectedImage->pixel(x_source-1, y_source+1);
            down = selectedImage->pixel(x_source, y_source+1);
            rightDown = selectedImage->pixel(x_source+1, y_source+1);

            red = (qRed(leftUpper) + qRed(upper) + qRed(rightupper) + qRed(left) + qRed(right) + qRed(leftDown) + qRed(down) + qRed(rightDown))/8.0;

            green = (qGreen(leftUpper) + qGreen(upper) + qGreen(rightupper) + qGreen(left) + qGreen(right) + qGreen(leftDown) + qGreen(down) + qGreen(rightDown))/8.0;

            blue = (qBlue(leftUpper) + qBlue(upper) + qBlue(rightupper) + qBlue(left) + qBlue(right) + qBlue(leftDown) + qBlue(down) + qBlue(rightDown))/8.0;

            average = qRgb(red, green, blue);

            targetImg->setPixel(i, j, average);
        }
    }

    ui->imgResult->setGeometry(ui->imgResult->x(), ui->imgResult->y(), targetImg->width(), targetImg->height());
    ui->imgResult->setPixmap(QPixmap::fromImage(*targetImg));
}

void MainWindow::crop(void)
{
    int newStartX = ui->labelStartXposition->text().toInt(0);
    int newStartY = ui->labelStartYposition->text().toInt(0);
    int newEndX = ui->labelEndXposition->text().toInt(0);
    int newEndY = ui->labelEndYposition->text().toInt(0);
    int width = newEndX-newStartX;
    int height = newEndY-newStartY;

    qDebug() << "Foi chamado o crop:";
    qDebug() << "from (" << newStartX << "," << newStartY
             << ") to (" << newEndX << "," << newEndY << ")";

    if( (width > 0 && height >0)
        &&
        (newStartX > 0 && newStartY > 0 && newEndX > 0 && newEndY > 0)
        &&
        (newStartX+width < selectedImage->width() && newStartY+height < selectedImage->height() &&
         newEndX < selectedImage->width() && newEndY < selectedImage->height()))
    {

        simpleCrop(newStartX, newStartY, newEndX, newEndY);
    }
}

void MainWindow::simpleCrop(int x1, int y1, int x2, int y2) {

    int target_width = x2 - x1;
    int target_height = y2 - y1;

    targetImg = new QImage(target_width, target_height, selectedImage->format());

    for (int i = 0; i < target_width; i++) {
        for (int j = 0; j < target_height; j++) {

            QRgb qrgb = selectedImage->pixel(x1 + i , y1 + j);
            targetImg->setPixel(i, j, qrgb);
        }
    }

    ui->imgResult->setGeometry(ui->imgResult->x(), ui->imgResult->y(), targetImg->width(), targetImg->height());
    ui->imgResult->setPixmap(QPixmap::fromImage(*targetImg));
}

void MainWindow::rotateRight() {
    qDebug() << "Foi chamada a rotacao a Direta";
    int target_width = selectedImage->width();
    int target_height = selectedImage->height();
    targetImg = new QImage(target_height, target_width, selectedImage->format());


    for (int i = 0; i < target_width; i++) {
        for (int j = 0; j < target_height; j++) {

            QRgb qrgb = selectedImage->pixel(i, j);
            targetImg->setPixel(target_height-j-1, i, qrgb);
        }
    }

    ui->imgResult->setGeometry(ui->imgResult->x(), ui->imgResult->y(), targetImg->width(), targetImg->height());
    ui->imgResult->setPixmap(QPixmap::fromImage(*targetImg));

}

void MainWindow::rotateLeft() {
    qDebug() << "Foi chamada a rotacao a Esquerda";
    int target_width = selectedImage->width();
    int target_height = selectedImage->height();
    targetImg = new QImage(target_height, target_width, selectedImage->format());


    for (int i = 0; i < target_width; i++) {
        for (int j = 0; j < target_height; j++) {

            QRgb qrgb = selectedImage->pixel(i, j);
            targetImg->setPixel(j, target_width-i, qrgb);
        }
    }

    ui->imgResult->setGeometry(ui->imgResult->x(), ui->imgResult->y(), targetImg->width(), targetImg->height());
    ui->imgResult->setPixmap(QPixmap::fromImage(*targetImg));

}

void MainWindow::mirror(void) {

    qDebug() << "Mirror.";
    int target_width = selectedImage->width();
    int target_height = selectedImage->height();
    targetImg = new QImage(target_width, target_height, selectedImage->format());


    for (int i = 0; i < target_width/2; i++) {
        for (int j = 0; j < target_height; j++) {

            QRgb qrgb = selectedImage->pixel(i, j);
            targetImg->setPixel(i, j, qrgb);
        }
    }

    for (int i = target_width/2; i < target_width; i++) {
        for (int j = 0; j < target_height; j++) {

            QRgb qrgb = selectedImage->pixel(target_width - i, j);
            targetImg->setPixel(i, j, qrgb);
        }
    }

    ui->imgResult->setGeometry(ui->imgResult->x(), ui->imgResult->y(), targetImg->width(), targetImg->height());
    ui->imgResult->setPixmap(QPixmap::fromImage(*targetImg));
}

void MainWindow::reflection(void) {

    qDebug() << "Reflection.";
    int target_width = selectedImage->width();
    int target_height = selectedImage->height();
    targetImg = new QImage(target_width, target_height, selectedImage->format());


    for (int i = 0; i < target_width; i++) {
        for (int j = 0; j < target_height; j++) {

            QRgb qrgb = selectedImage->pixel(target_width - i, j);
            targetImg->setPixel(i, j, qrgb);
        }
    }

    ui->imgResult->setGeometry(ui->imgResult->x(), ui->imgResult->y(), targetImg->width(), targetImg->height());
    ui->imgResult->setPixmap(QPixmap::fromImage(*targetImg));
}

void MainWindow::grayScale(void) {

    qDebug() << "grayScale.";
    int target_width = selectedImage->width();
    int target_height = selectedImage->height();
    int media;
    targetImg = new QImage(target_width, target_height, selectedImage->format());


    for (int i = 0; i < target_width; i++) {
        for (int j = 0; j < target_height; j++) {

            QRgb qrgb = selectedImage->pixel(i, j);
            media = (qBlue(qrgb) + qGreen(qrgb) + qRed(qrgb)) / 3;
            QRgb grayPixel = qRgb(media, media, media);
            targetImg->setPixel(i, j, grayPixel);
        }
    }

    ui->imgResult->setGeometry(ui->imgResult->x(), ui->imgResult->y(), targetImg->width(), targetImg->height());
    ui->imgResult->setPixmap(QPixmap::fromImage(*targetImg));
}

void MainWindow::xray(void) {

    qDebug() << "xray.";
    int target_width = selectedImage->width();
    int target_height = selectedImage->height();

    targetImg = new QImage(target_width, target_height, selectedImage->format());


    for (int i = 0; i < target_width; i++) {
        for (int j = 0; j < target_height; j++) {

            QRgb qrgb = selectedImage->pixel(i, j);            
            QRgb xraypixel = qRgb(qRed(qrgb) ^ 255, qGreen(qrgb) ^ 255, qBlue(qrgb) ^ 255);

            targetImg->setPixel(i, j, xraypixel);
        }
    }

    ui->imgResult->setGeometry(ui->imgResult->x(), ui->imgResult->y(), targetImg->width(), targetImg->height());
    ui->imgResult->setPixmap(QPixmap::fromImage(*targetImg));
}


void MainWindow::sepia(void) {

    qDebug() << "sepia.";
    int target_width = selectedImage->width();
    int target_height = selectedImage->height();
    int red, green, blue;

    targetImg = new QImage(target_width, target_height, selectedImage->format());


    for (int i = 0; i < target_width; i++) {
        for (int j = 0; j < target_height; j++) {

            QRgb qrgb = selectedImage->pixel(i, j);

            red = (0.393*qRed(qrgb) + 0.769*qGreen(qrgb) + 0.189*qBlue(qrgb));
            green = (0.349*qRed(qrgb) + 0.686*qGreen(qrgb) + 0.168*qBlue(qrgb));
            blue = (0.272*qRed(qrgb) + 0.534*qGreen(qrgb) + 0.131*qBlue(qrgb));

            if (red>0xFF) red=0xFF;
            if (green>0xFF) green=0xFF;
            if (blue>0xFF) blue=0xFF;

            QRgb sepiaPixel = qRgb(red, green, blue);

            targetImg->setPixel(i, j, sepiaPixel);
        }
    }

    ui->imgResult->setGeometry(ui->imgResult->x(), ui->imgResult->y(), targetImg->width(), targetImg->height());
    ui->imgResult->setPixmap(QPixmap::fromImage(*targetImg));
}
