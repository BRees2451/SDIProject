/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../SDIProject-master/QTPracticeNew/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[336];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 23), // "on_ZoomInButton_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 24), // "on_ZoomOutButton_clicked"
QT_MOC_LITERAL(4, 61, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(5, 85, 23), // "on_actionQuit_triggered"
QT_MOC_LITERAL(6, 109, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(7, 133, 25), // "on_DrawRectButton_clicked"
QT_MOC_LITERAL(8, 159, 29), // "on_DrawTriangleButton_clicked"
QT_MOC_LITERAL(9, 189, 24), // "on_RotateLButton_clicked"
QT_MOC_LITERAL(10, 214, 24), // "on_RotateRButton_clicked"
QT_MOC_LITERAL(11, 239, 25), // "on_AddImageButton_clicked"
QT_MOC_LITERAL(12, 265, 17), // "showMousePosition"
QT_MOC_LITERAL(13, 283, 7), // "QPoint&"
QT_MOC_LITERAL(14, 291, 3), // "pos"
QT_MOC_LITERAL(15, 295, 15), // "mousePressEvent"
QT_MOC_LITERAL(16, 311, 12), // "QMouseEvent*"
QT_MOC_LITERAL(17, 324, 11) // "mouse_event"

    },
    "MainWindow\0on_ZoomInButton_clicked\0\0"
    "on_ZoomOutButton_clicked\0"
    "on_actionOpen_triggered\0on_actionQuit_triggered\0"
    "on_actionSave_triggered\0"
    "on_DrawRectButton_clicked\0"
    "on_DrawTriangleButton_clicked\0"
    "on_RotateLButton_clicked\0"
    "on_RotateRButton_clicked\0"
    "on_AddImageButton_clicked\0showMousePosition\0"
    "QPoint&\0pos\0mousePressEvent\0QMouseEvent*\0"
    "mouse_event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    1,   84,    2, 0x0a /* Public */,
      15,    1,   87,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 16,   17,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ZoomInButton_clicked(); break;
        case 1: _t->on_ZoomOutButton_clicked(); break;
        case 2: _t->on_actionOpen_triggered(); break;
        case 3: _t->on_actionQuit_triggered(); break;
        case 4: _t->on_actionSave_triggered(); break;
        case 5: _t->on_DrawRectButton_clicked(); break;
        case 6: _t->on_DrawTriangleButton_clicked(); break;
        case 7: _t->on_RotateLButton_clicked(); break;
        case 8: _t->on_RotateRButton_clicked(); break;
        case 9: _t->on_AddImageButton_clicked(); break;
        case 10: _t->showMousePosition((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 11: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
