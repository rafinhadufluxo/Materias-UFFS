/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun Sep 4 13:47:32 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      23,   11,   11,   11, 0x0a,
      38,   11,   11,   11, 0x0a,
      49,   11,   11,   11, 0x0a,
      56,   11,   11,   11, 0x0a,
      66,   11,   11,   11, 0x0a,
      73,   11,   11,   11, 0x0a,
      82,   11,   11,   11, 0x0a,
      89,   11,   11,   11, 0x0a,
     103,   11,   11,   11, 0x0a,
     116,   11,   11,   11, 0x0a,
     125,   11,   11,   11, 0x0a,
     138,   11,   11,   11, 0x0a,
     150,   11,   11,   11, 0x0a,
     157,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0openFile()\0applyChanges()\0"
    "saveFile()\0exit()\0effects()\0zoom()\0"
    "resize()\0crop()\0rotateRight()\0"
    "rotateLeft()\0mirror()\0reflection()\0"
    "grayScale()\0xray()\0sepia()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: openFile(); break;
        case 1: applyChanges(); break;
        case 2: saveFile(); break;
        case 3: exit(); break;
        case 4: effects(); break;
        case 5: zoom(); break;
        case 6: resize(); break;
        case 7: crop(); break;
        case 8: rotateRight(); break;
        case 9: rotateLeft(); break;
        case 10: mirror(); break;
        case 11: reflection(); break;
        case 12: grayScale(); break;
        case 13: xray(); break;
        case 14: sepia(); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
