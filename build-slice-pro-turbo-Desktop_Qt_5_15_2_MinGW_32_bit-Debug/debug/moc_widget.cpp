/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../slice-pro-turbo/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[28];
    char stringdata0[408];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 9), // "stlOpened"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 6), // "QFile*"
QT_MOC_LITERAL(4, 25, 4), // "file"
QT_MOC_LITERAL(5, 30, 15), // "toggleWireframe"
QT_MOC_LITERAL(6, 46, 4), // "show"
QT_MOC_LITERAL(7, 51, 9), // "sliceAuto"
QT_MOC_LITERAL(8, 61, 13), // "sliceAdaptive"
QT_MOC_LITERAL(9, 75, 5), // "width"
QT_MOC_LITERAL(10, 81, 15), // "createGCodeFile"
QT_MOC_LITERAL(11, 97, 12), // "resetSlicing"
QT_MOC_LITERAL(12, 110, 10), // "rotateBody"
QT_MOC_LITERAL(13, 121, 4), // "axis"
QT_MOC_LITERAL(14, 126, 12), // "intersection"
QT_MOC_LITERAL(15, 139, 7), // "checked"
QT_MOC_LITERAL(16, 147, 21), // "setGridInIntersection"
QT_MOC_LITERAL(17, 169, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(18, 193, 19), // "on_checkBox_toggled"
QT_MOC_LITERAL(19, 213, 20), // "on_SliceAuto_clicked"
QT_MOC_LITERAL(20, 234, 20), // "on_saveGCode_clicked"
QT_MOC_LITERAL(21, 255, 22), // "on_ResetButton_clicked"
QT_MOC_LITERAL(22, 278, 18), // "on_RotateX_clicked"
QT_MOC_LITERAL(23, 297, 18), // "on_RotateY_clicked"
QT_MOC_LITERAL(24, 316, 18), // "on_RotateZ_clicked"
QT_MOC_LITERAL(25, 335, 24), // "on_SliceAdaptive_clicked"
QT_MOC_LITERAL(26, 360, 23), // "on_intersection_toggled"
QT_MOC_LITERAL(27, 384, 23) // "on_pushButton_3_clicked"

    },
    "Widget\0stlOpened\0\0QFile*\0file\0"
    "toggleWireframe\0show\0sliceAuto\0"
    "sliceAdaptive\0width\0createGCodeFile\0"
    "resetSlicing\0rotateBody\0axis\0intersection\0"
    "checked\0setGridInIntersection\0"
    "on_pushButton_2_clicked\0on_checkBox_toggled\0"
    "on_SliceAuto_clicked\0on_saveGCode_clicked\0"
    "on_ResetButton_clicked\0on_RotateX_clicked\0"
    "on_RotateY_clicked\0on_RotateZ_clicked\0"
    "on_SliceAdaptive_clicked\0"
    "on_intersection_toggled\0on_pushButton_3_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  114,    2, 0x06 /* Public */,
       5,    1,  117,    2, 0x06 /* Public */,
       7,    0,  120,    2, 0x06 /* Public */,
       8,    1,  121,    2, 0x06 /* Public */,
      10,    1,  124,    2, 0x06 /* Public */,
      11,    0,  127,    2, 0x06 /* Public */,
      12,    1,  128,    2, 0x06 /* Public */,
      14,    1,  131,    2, 0x06 /* Public */,
      16,    0,  134,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    0,  135,    2, 0x08 /* Private */,
      18,    1,  136,    2, 0x08 /* Private */,
      19,    0,  139,    2, 0x08 /* Private */,
      20,    0,  140,    2, 0x08 /* Private */,
      21,    0,  141,    2, 0x08 /* Private */,
      22,    0,  142,    2, 0x08 /* Private */,
      23,    0,  143,    2, 0x08 /* Private */,
      24,    0,  144,    2, 0x08 /* Private */,
      25,    0,  145,    2, 0x08 /* Private */,
      26,    1,  146,    2, 0x08 /* Private */,
      27,    0,  149,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stlOpened((*reinterpret_cast< QFile*(*)>(_a[1]))); break;
        case 1: _t->toggleWireframe((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->sliceAuto(); break;
        case 3: _t->sliceAdaptive((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->createGCodeFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->resetSlicing(); break;
        case 6: _t->rotateBody((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->intersection((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->setGridInIntersection(); break;
        case 9: _t->on_pushButton_2_clicked(); break;
        case 10: _t->on_checkBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_SliceAuto_clicked(); break;
        case 12: _t->on_saveGCode_clicked(); break;
        case 13: _t->on_ResetButton_clicked(); break;
        case 14: _t->on_RotateX_clicked(); break;
        case 15: _t->on_RotateY_clicked(); break;
        case 16: _t->on_RotateZ_clicked(); break;
        case 17: _t->on_SliceAdaptive_clicked(); break;
        case 18: _t->on_intersection_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->on_pushButton_3_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QFile* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Widget::*)(QFile * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::stlOpened)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Widget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::toggleWireframe)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Widget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::sliceAuto)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Widget::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::sliceAdaptive)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Widget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::createGCodeFile)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Widget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::resetSlicing)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Widget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::rotateBody)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Widget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::intersection)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Widget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::setGridInIntersection)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Widget.data,
    qt_meta_data_Widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void Widget::stlOpened(QFile * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Widget::toggleWireframe(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Widget::sliceAuto()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Widget::sliceAdaptive(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Widget::createGCodeFile(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Widget::resetSlicing()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Widget::rotateBody(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Widget::intersection(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Widget::setGridInIntersection()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
