/****************************************************************************
** Meta object code from reading C++ file 'glwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../slice-pro-turbo/glwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'glwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GLWidget_t {
    QByteArrayData data[30];
    char stringdata0[352];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GLWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GLWidget_t qt_meta_stringdata_GLWidget = {
    {
QT_MOC_LITERAL(0, 0, 8), // "GLWidget"
QT_MOC_LITERAL(1, 9, 16), // "xRotationChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "angle"
QT_MOC_LITERAL(4, 33, 16), // "yRotationChanged"
QT_MOC_LITERAL(5, 50, 16), // "zRotationChanged"
QT_MOC_LITERAL(6, 67, 19), // "disableIntersection"
QT_MOC_LITERAL(7, 87, 11), // "showMessage"
QT_MOC_LITERAL(8, 99, 4), // "text"
QT_MOC_LITERAL(9, 104, 20), // "showStatusBarMessage"
QT_MOC_LITERAL(10, 125, 12), // "setXRotation"
QT_MOC_LITERAL(11, 138, 12), // "setYRotation"
QT_MOC_LITERAL(12, 151, 12), // "setZRotation"
QT_MOC_LITERAL(13, 164, 6), // "getStl"
QT_MOC_LITERAL(14, 171, 6), // "QFile*"
QT_MOC_LITERAL(15, 178, 4), // "file"
QT_MOC_LITERAL(16, 183, 15), // "toggleWireframe"
QT_MOC_LITERAL(17, 199, 4), // "show"
QT_MOC_LITERAL(18, 204, 9), // "sliceAuto"
QT_MOC_LITERAL(19, 214, 13), // "sliceAdaptive"
QT_MOC_LITERAL(20, 228, 5), // "width"
QT_MOC_LITERAL(21, 234, 15), // "createGCodeFile"
QT_MOC_LITERAL(22, 250, 8), // "fileName"
QT_MOC_LITERAL(23, 259, 15), // "resetSliceState"
QT_MOC_LITERAL(24, 275, 10), // "rotateBody"
QT_MOC_LITERAL(25, 286, 4), // "axis"
QT_MOC_LITERAL(26, 291, 12), // "intersection"
QT_MOC_LITERAL(27, 304, 7), // "checked"
QT_MOC_LITERAL(28, 312, 18), // "setInnerPointsGrid"
QT_MOC_LITERAL(29, 331, 20) // "createDiagramVoronov"

    },
    "GLWidget\0xRotationChanged\0\0angle\0"
    "yRotationChanged\0zRotationChanged\0"
    "disableIntersection\0showMessage\0text\0"
    "showStatusBarMessage\0setXRotation\0"
    "setYRotation\0setZRotation\0getStl\0"
    "QFile*\0file\0toggleWireframe\0show\0"
    "sliceAuto\0sliceAdaptive\0width\0"
    "createGCodeFile\0fileName\0resetSliceState\0"
    "rotateBody\0axis\0intersection\0checked\0"
    "setInnerPointsGrid\0createDiagramVoronov"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GLWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x06 /* Public */,
       4,    1,  112,    2, 0x06 /* Public */,
       5,    1,  115,    2, 0x06 /* Public */,
       6,    0,  118,    2, 0x06 /* Public */,
       7,    1,  119,    2, 0x06 /* Public */,
       9,    1,  122,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,  125,    2, 0x0a /* Public */,
      11,    1,  128,    2, 0x0a /* Public */,
      12,    1,  131,    2, 0x0a /* Public */,
      13,    1,  134,    2, 0x0a /* Public */,
      16,    1,  137,    2, 0x0a /* Public */,
      18,    0,  140,    2, 0x0a /* Public */,
      19,    1,  141,    2, 0x0a /* Public */,
      21,    1,  144,    2, 0x0a /* Public */,
      23,    0,  147,    2, 0x0a /* Public */,
      24,    1,  148,    2, 0x0a /* Public */,
      26,    1,  151,    2, 0x0a /* Public */,
      28,    0,  154,    2, 0x0a /* Public */,
      29,    0,  155,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   20,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GLWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->xRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->yRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->zRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->disableIntersection(); break;
        case 4: _t->showMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->showStatusBarMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->setXRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setYRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setZRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->getStl((*reinterpret_cast< QFile*(*)>(_a[1]))); break;
        case 10: _t->toggleWireframe((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->sliceAuto(); break;
        case 12: _t->sliceAdaptive((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->createGCodeFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->resetSliceState(); break;
        case 15: _t->rotateBody((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->intersection((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->setInnerPointsGrid(); break;
        case 18: _t->createDiagramVoronov(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
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
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::xRotationChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::yRotationChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::zRotationChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::disableIntersection)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::showMessage)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::showStatusBarMessage)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GLWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QGLWidget::staticMetaObject>(),
    qt_meta_stringdata_GLWidget.data,
    qt_meta_data_GLWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GLWidget.stringdata0))
        return static_cast<void*>(this);
    return QGLWidget::qt_metacast(_clname);
}

int GLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void GLWidget::xRotationChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GLWidget::yRotationChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GLWidget::zRotationChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GLWidget::disableIntersection()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void GLWidget::showMessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GLWidget::showStatusBarMessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
