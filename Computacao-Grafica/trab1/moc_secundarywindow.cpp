/****************************************************************************
** Meta object code from reading C++ file 'secundarywindow.h'
**
** Created: Mon Sep 5 09:22:04 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "secundarywindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'secundarywindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SecundaryWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      32,   16,   16,   16, 0x0a,
      42,   16,   16,   16, 0x0a,
      52,   16,   16,   16, 0x0a,
      62,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SecundaryWindow[] = {
    "SecundaryWindow\0\0applyChanges()\0"
    "changeR()\0changeG()\0changeB()\0"
    "changeBrightness()\0"
};

const QMetaObject SecundaryWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SecundaryWindow,
      qt_meta_data_SecundaryWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SecundaryWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SecundaryWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SecundaryWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SecundaryWindow))
        return static_cast<void*>(const_cast< SecundaryWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SecundaryWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: applyChanges(); break;
        case 1: changeR(); break;
        case 2: changeG(); break;
        case 3: changeB(); break;
        case 4: changeBrightness(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
