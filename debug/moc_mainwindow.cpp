/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[30];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 9), // "addVertex"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 7), // "addEdge"
QT_MOC_LITERAL(30, 4), // "drag"
QT_MOC_LITERAL(35, 12), // "removeVertex"
QT_MOC_LITERAL(48, 10), // "removeEdge"
QT_MOC_LITERAL(59, 15), // "mousePressEvent"
QT_MOC_LITERAL(75, 12), // "QMouseEvent*"
QT_MOC_LITERAL(88, 5), // "event"
QT_MOC_LITERAL(94, 4), // "save"
QT_MOC_LITERAL(99, 4), // "load"
QT_MOC_LITERAL(104, 8), // "loadFile"
QT_MOC_LITERAL(113, 5), // "clear"
QT_MOC_LITERAL(119, 15) // "on_next_clicked"

    },
    "MainWindow\0addVertex\0\0addEdge\0drag\0"
    "removeVertex\0removeEdge\0mousePressEvent\0"
    "QMouseEvent*\0event\0save\0load\0loadFile\0"
    "clear\0on_next_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x0a,    0 /* Public */,
       3,    0,   81,    2, 0x0a,    1 /* Public */,
       4,    0,   82,    2, 0x0a,    2 /* Public */,
       5,    0,   83,    2, 0x0a,    3 /* Public */,
       6,    0,   84,    2, 0x0a,    4 /* Public */,
       7,    1,   85,    2, 0x0a,    5 /* Public */,
      10,    0,   88,    2, 0x0a,    7 /* Public */,
      11,    1,   89,    2, 0x0a,    8 /* Public */,
      11,    0,   92,    2, 0x2a,   10 /* Public | MethodCloned */,
      13,    0,   93,    2, 0x0a,   11 /* Public */,
      14,    0,   94,    2, 0x0a,   12 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->addVertex(); break;
        case 1: _t->addEdge(); break;
        case 2: _t->drag(); break;
        case 3: _t->removeVertex(); break;
        case 4: _t->removeEdge(); break;
        case 5: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 6: _t->save(); break;
        case 7: _t->load((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->load(); break;
        case 9: _t->clear(); break;
        case 10: _t->on_next_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
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
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
