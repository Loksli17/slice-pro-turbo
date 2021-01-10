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
    QByteArrayData data[33];
    char stringdata0[483];
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
QT_MOC_LITERAL(17, 169, 20), // "createDiagramVoronov"
QT_MOC_LITERAL(18, 190, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(19, 214, 19), // "on_checkBox_toggled"
QT_MOC_LITERAL(20, 234, 20), // "on_SliceAuto_clicked"
QT_MOC_LITERAL(21, 255, 20), // "on_saveGCode_clicked"
QT_MOC_LITERAL(22, 276, 22), // "on_ResetButton_clicked"
QT_MOC_LITERAL(23, 299, 18), // "on_RotateX_clicked"
QT_MOC_LITERAL(24, 318, 18), // "on_RotateY_clicked"
QT_MOC_LITERAL(25, 337, 18), // "on_RotateZ_clicked"
QT_MOC_LITERAL(26, 356, 24), // "on_SliceAdaptive_clicked"
QT_MOC_LITERAL(27, 381, 23), // "on_intersection_toggled"
QT_MOC_LITERAL(28, 405, 19), // "disableIntersection"
QT_MOC_LITERAL(29, 425, 11), // "showMessage"
QT_MOC_LITERAL(30, 437, 4), // "text"
QT_MOC_LITERAL(31, 442, 20), // "showStatusBarMessage"
QT_MOC_LITERAL(32, 463, 19) // "on_drawGrid_clicked"

    },
    "Widget\0stlOpened\0\0QFile*\0file\0"
    "toggleWireframe\0show\0sliceAuto\0"
    "sliceAdaptive\0width\0createGCodeFile\0"
    "resetSlicing\0rotateBody\0axis\0intersection\0"
    "checked\0setGridInIntersection\0"
    "createDiagramVoronov\0on_pushButton_2_clicked\0"
    "on_checkBox_toggled\0on_SliceAuto_clicked\0"
    "on_saveGCode_clicked\0on_ResetButton_clicked\0"
    "on_RotateX_clicked\0on_RotateY_clicked\0"
    "on_RotateZ_clicked\0on_SliceAdaptive_clicked\0"
    "on_intersection_toggled\0disableIntersection\0"
    "showMessage\0text\0showStatusBarMessage\0"
    "on_drawGrid_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  134,    2, 0x06 /* Public */,
       5,    1,  137,    2, 0x06 /* Public */,
       7,    0,  140,    2, 0x06 /* Public */,
       8,    1,  141,    2, 0x06 /* Public */,
      10,    1,  144,    2, 0x06 /* Public */,
      11,    0,  147,    2, 0x06 /* Public */,
      12,    1,  148,    2, 0x06 /* Public */,
      14,    1,  151,    2, 0x06 /* Public */,
      16,    0,  154,    2, 0x06 /* Public */,
      17,    0,  155,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    0,  156,    2, 0x08 /* Private */,
      19,    1,  157,    2, 0x08 /* Private */,
      20,    0,  160,    2, 0x08 /* Private */,
      21,    0,  161,    2, 0x08 /* Private */,
      22,    0,  162,    2, 0x08 /* Private */,
      23,    0,  163,    2, 0x08 /* Private */,
      24,    0,  164,    2, 0x08 /* Private */,
      25,    0,  165,    2, 0x08 /* Private */,
      26,    0,  166,    2, 0x08 /* Private */,
      27,    1,  167,    2, 0x08 /* Private */,
      28,    0,  170,    2, 0x08 /* Private */,
      29,    1,  171,    2, 0x08 /* Private */,
      31,    1,  174,    2, 0x08 /* Private */,
      32,    0,  177,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::QString,   30,
    QMetaType::Void, QMetaType::QString,   30,
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
        case 9: _t->createDiagramVoronov(); break;
        case 10: _t->on_pushButton_2_clicked(); break;
        case 11: _t->on_checkBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_SliceAuto_clicked(); break;
        case 13: _t->on_saveGCode_clicked(); break;
        case 14: _t->on_ResetButton_clicked(); break;
        case 15: _t->on_RotateX_clicked(); break;
        case 16: _t->on_RotateY_clicked(); break;
        case 17: _t->on_RotateZ_clicked(); break;
        case 18: _t->on_SliceAdaptive_clicked(); break;
        case 19: _t->on_intersection_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->disableIntersection(); break;
        case 21: _t->showMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: _t->showStatusBarMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: _t->on_drawGrid_clicked(); break;
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
        {
            using _t = void (Widget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::createDiagramVoronov)) {
                *result = 9;
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
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
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

// SIGNAL 9
void Widget::createDiagramVoronov()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
