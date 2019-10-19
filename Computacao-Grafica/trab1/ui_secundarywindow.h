/********************************************************************************
** Form generated from reading UI file 'secundarywindow.ui'
**
** Created: Mon Sep 5 09:21:57 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECUNDARYWINDOW_H
#define UI_SECUNDARYWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SecundaryWindow
{
public:
    QSlider *rSlider;
    QSlider *gSlider;
    QSlider *bSlider;
    QLabel *RGBlabel;
    QPushButton *applyChanges;
    QLabel *labelLess;
    QLabel *labelMore;
    QLabel *labelColors;
    QFrame *line;
    QSlider *brightnessSlider;
    QLabel *labelBrightness;
    QFrame *line_2;
    QLabel *labelLess_2;
    QLabel *labelMore_2;

    void setupUi(QWidget *SecundaryWindow)
    {
        if (SecundaryWindow->objectName().isEmpty())
            SecundaryWindow->setObjectName(QString::fromUtf8("SecundaryWindow"));
        SecundaryWindow->setWindowModality(Qt::NonModal);
        SecundaryWindow->resize(223, 293);
        rSlider = new QSlider(SecundaryWindow);
        rSlider->setObjectName(QString::fromUtf8("rSlider"));
        rSlider->setGeometry(QRect(23, 60, 22, 160));
        rSlider->setMaximum(255);
        rSlider->setPageStep(1);
        rSlider->setValue(255);
        rSlider->setOrientation(Qt::Vertical);
        gSlider = new QSlider(SecundaryWindow);
        gSlider->setObjectName(QString::fromUtf8("gSlider"));
        gSlider->setGeometry(QRect(53, 60, 22, 160));
        gSlider->setMaximum(255);
        gSlider->setPageStep(1);
        gSlider->setValue(255);
        gSlider->setOrientation(Qt::Vertical);
        bSlider = new QSlider(SecundaryWindow);
        bSlider->setObjectName(QString::fromUtf8("bSlider"));
        bSlider->setGeometry(QRect(83, 60, 22, 160));
        bSlider->setMaximum(255);
        bSlider->setPageStep(1);
        bSlider->setValue(255);
        bSlider->setOrientation(Qt::Vertical);
        RGBlabel = new QLabel(SecundaryWindow);
        RGBlabel->setObjectName(QString::fromUtf8("RGBlabel"));
        RGBlabel->setGeometry(QRect(30, 40, 81, 16));
        applyChanges = new QPushButton(SecundaryWindow);
        applyChanges->setObjectName(QString::fromUtf8("applyChanges"));
        applyChanges->setGeometry(QRect(50, 240, 121, 32));
        labelLess = new QLabel(SecundaryWindow);
        labelLess->setObjectName(QString::fromUtf8("labelLess"));
        labelLess->setGeometry(QRect(10, 60, 16, 16));
        labelLess->setAlignment(Qt::AlignCenter);
        labelMore = new QLabel(SecundaryWindow);
        labelMore->setObjectName(QString::fromUtf8("labelMore"));
        labelMore->setGeometry(QRect(10, 205, 16, 16));
        labelMore->setAlignment(Qt::AlignCenter);
        labelColors = new QLabel(SecundaryWindow);
        labelColors->setObjectName(QString::fromUtf8("labelColors"));
        labelColors->setGeometry(QRect(10, 10, 62, 16));
        line = new QFrame(SecundaryWindow);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 30, 118, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        brightnessSlider = new QSlider(SecundaryWindow);
        brightnessSlider->setObjectName(QString::fromUtf8("brightnessSlider"));
        brightnessSlider->setGeometry(QRect(160, 60, 22, 160));
        brightnessSlider->setMaximum(255);
        brightnessSlider->setPageStep(1);
        brightnessSlider->setValue(127);
        brightnessSlider->setOrientation(Qt::Vertical);
        labelBrightness = new QLabel(SecundaryWindow);
        labelBrightness->setObjectName(QString::fromUtf8("labelBrightness"));
        labelBrightness->setGeometry(QRect(140, 10, 71, 16));
        line_2 = new QFrame(SecundaryWindow);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(140, 30, 69, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        labelLess_2 = new QLabel(SecundaryWindow);
        labelLess_2->setObjectName(QString::fromUtf8("labelLess_2"));
        labelLess_2->setGeometry(QRect(150, 60, 16, 16));
        labelLess_2->setAlignment(Qt::AlignCenter);
        labelMore_2 = new QLabel(SecundaryWindow);
        labelMore_2->setObjectName(QString::fromUtf8("labelMore_2"));
        labelMore_2->setGeometry(QRect(150, 205, 16, 16));
        labelMore_2->setAlignment(Qt::AlignCenter);

        retranslateUi(SecundaryWindow);

        QMetaObject::connectSlotsByName(SecundaryWindow);
    } // setupUi

    void retranslateUi(QWidget *SecundaryWindow)
    {
        SecundaryWindow->setWindowTitle(QApplication::translate("SecundaryWindow", "Effects", 0, QApplication::UnicodeUTF8));
        RGBlabel->setText(QApplication::translate("SecundaryWindow", "R     G     B", 0, QApplication::UnicodeUTF8));
        applyChanges->setText(QApplication::translate("SecundaryWindow", "Apply Changes", 0, QApplication::UnicodeUTF8));
        labelLess->setText(QApplication::translate("SecundaryWindow", "-", 0, QApplication::UnicodeUTF8));
        labelMore->setText(QApplication::translate("SecundaryWindow", "+", 0, QApplication::UnicodeUTF8));
        labelColors->setText(QApplication::translate("SecundaryWindow", "Colors", 0, QApplication::UnicodeUTF8));
        labelBrightness->setText(QApplication::translate("SecundaryWindow", "Brightness", 0, QApplication::UnicodeUTF8));
        labelLess_2->setText(QApplication::translate("SecundaryWindow", "-", 0, QApplication::UnicodeUTF8));
        labelMore_2->setText(QApplication::translate("SecundaryWindow", "+", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SecundaryWindow: public Ui_SecundaryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECUNDARYWINDOW_H
