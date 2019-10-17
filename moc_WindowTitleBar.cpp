/****************************************************************************
** Meta object code from reading C++ file 'WindowTitleBar.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "inc/Widgets/WindowTitleBar.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WindowTitleBar.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WindowTitleBar_t {
    QByteArrayData data[10];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WindowTitleBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WindowTitleBar_t qt_meta_stringdata_WindowTitleBar = {
    {
QT_MOC_LITERAL(0, 0, 14), // "WindowTitleBar"
QT_MOC_LITERAL(1, 15, 17), // "UpdateWindowTitle"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 5), // "title"
QT_MOC_LITERAL(4, 40, 17), // "ApplyResizeChange"
QT_MOC_LITERAL(5, 58, 5), // "state"
QT_MOC_LITERAL(6, 64, 18), // "ApplyTitleBarState"
QT_MOC_LITERAL(7, 83, 9), // "Minimized"
QT_MOC_LITERAL(8, 93, 9), // "Maximized"
QT_MOC_LITERAL(9, 103, 4) // "Quit"

    },
    "WindowTitleBar\0UpdateWindowTitle\0\0"
    "title\0ApplyResizeChange\0state\0"
    "ApplyTitleBarState\0Minimized\0Maximized\0"
    "Quit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WindowTitleBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       4,    1,   47,    2, 0x0a /* Public */,
       6,    1,   50,    2, 0x0a /* Public */,
       7,    0,   53,    2, 0x0a /* Public */,
       8,    0,   54,    2, 0x0a /* Public */,
       9,    0,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WindowTitleBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WindowTitleBar *_t = static_cast<WindowTitleBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->UpdateWindowTitle((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->ApplyResizeChange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->ApplyTitleBarState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->Minimized(); break;
        case 4: _t->Maximized(); break;
        case 5: _t->Quit(); break;
        default: ;
        }
    }
}

const QMetaObject WindowTitleBar::staticMetaObject = {
    { &Widget::staticMetaObject, qt_meta_stringdata_WindowTitleBar.data,
      qt_meta_data_WindowTitleBar,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WindowTitleBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WindowTitleBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WindowTitleBar.stringdata0))
        return static_cast<void*>(this);
    return Widget::qt_metacast(_clname);
}

int WindowTitleBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Widget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
