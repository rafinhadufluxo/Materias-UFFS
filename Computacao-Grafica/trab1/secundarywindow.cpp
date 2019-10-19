#include "secundarywindow.h"
#include "mainwindow.h"
#include "ui_secundarywindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

SecundaryWindow::SecundaryWindow(QWidget *parent, Ui::MainWindow *ui, QImage *selectedImage, QImage *targetImg) :
    QMainWindow(parent),
    effect(new Ui::SecundaryWindow)
{
    effect->setupUi(this);

    main = ui;
    selected = selectedImage;
    target = targetImg;

    connect(effect->applyChanges, SIGNAL(clicked()), this, SLOT(applyChanges()));

    connect(effect->rSlider, SIGNAL(sliderReleased()), this, SLOT(changeR()));
    connect(effect->gSlider, SIGNAL(sliderReleased()), this, SLOT(changeG()));
    connect(effect->bSlider, SIGNAL(sliderReleased()), this, SLOT(changeB()));

    connect(effect->brightnessSlider, SIGNAL(sliderReleased()), this, SLOT(changeBrightness()));
}

SecundaryWindow::~SecundaryWindow()
{
    delete effect;
}

void SecundaryWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        effect->retranslateUi(this);
        break;
    default:
        break;
    }
}

void SecundaryWindow::applyChanges(void)
{
    qDebug() << "Salvou a alteracao feita em Effects";
    main->imgSelected->setPixmap(QPixmap::fromImage(*target));
    selected = target;
}

void SecundaryWindow::changeR(void)
{
    qDebug() << "Alterando o Red";
    int width = selected->width();
    int height = selected->height();
    int red, green, blue;
    int sliderValue = effect->brightnessSlider->value();

    QRgb qrgb = qRgb(0,0,0);

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {

            qrgb = selected->pixel(i, j);

            red = qRed(qrgb);
            green = qGreen(qrgb)*(sliderValue/255.0);
            blue = qBlue(qrgb)*(sliderValue/255.0);

            qrgb = qRgb(red, green, blue);

            target->setPixel(i, j, qrgb);
        }
    }

    main->imgResult->setPixmap(QPixmap::fromImage(*target));
}

void SecundaryWindow::changeG(void)
{
    qDebug() << "Alterando o Green";
    int width = selected->width();
    int height = selected->height();
    int red, green, blue;
    int sliderValue = effect->brightnessSlider->value();

    QRgb qrgb = qRgb(0,0,0);

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {

            qrgb = selected->pixel(i, j);

            red = qRed(qrgb)*(sliderValue/255.0);
            green = qGreen(qrgb);
            blue = qBlue(qrgb)*(sliderValue/255.0);

            qrgb = qRgb(red, green, blue);

            target->setPixel(i, j, qrgb);
        }
    }

    main->imgResult->setPixmap(QPixmap::fromImage(*target));
}

void SecundaryWindow::changeB(void)
{
    qDebug() << "Alterando o Blue";
    int width = selected->width();
    int height = selected->height();
    int red, green, blue;
    int sliderValue = effect->brightnessSlider->value();

    QRgb qrgb = qRgb(0,0,0);

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {

            qrgb = selected->pixel(i, j);

            red = qRed(qrgb)*(sliderValue/255.0);
            green = qGreen(qrgb)*(sliderValue/255.0);
            blue = qBlue(qrgb);

            qrgb = qRgb(red, green, blue);

            target->setPixel(i, j, qrgb);
        }
    }

    main->imgResult->setPixmap(QPixmap::fromImage(*target));
}

void SecundaryWindow::changeBrightness(void)
{
    qDebug() << "Alterando o Brightness";
    int width = selected->width();
    int height = selected->height();
    int red, green, blue;
    double sliderValue = effect->brightnessSlider->value();

    QRgb qrgb = qRgb(0,0,0);

    if(sliderValue > 127.0){
        sliderValue = (1.0/(255.0-sliderValue))+127.0;
    }else{
        sliderValue = 255.0+(127.0-sliderValue);
    }

    qDebug() << sliderValue;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {

            qrgb = selected->pixel(i, j);

            red = qRed(qrgb)*(sliderValue/255.0);
            green = qGreen(qrgb)*(sliderValue/255.0);
            blue = qBlue(qrgb)*(sliderValue/255.0);

            if (red>255.0) red=255.0;
            if (green>255.0) green=255.0;
            if (blue>255.0) blue=255.0;

            qrgb = qRgb(red, green, blue);

            target->setPixel(i, j, qrgb);
        }
    }

    main->imgResult->setPixmap(QPixmap::fromImage(*target));
}
