/****************************************************************************
** Meta object code from reading C++ file 'gamewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../conway/conway-master/gamewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameWidget_t {
    QByteArrayData data[26];
    char stringdata0[229];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameWidget_t qt_meta_stringdata_GameWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "GameWidget"
QT_MOC_LITERAL(1, 11, 18), // "environmentChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 2), // "ok"
QT_MOC_LITERAL(4, 34, 8), // "gameEnds"
QT_MOC_LITERAL(5, 43, 9), // "startGame"
QT_MOC_LITERAL(6, 53, 6), // "number"
QT_MOC_LITERAL(7, 60, 8), // "stopGame"
QT_MOC_LITERAL(8, 69, 5), // "clear"
QT_MOC_LITERAL(9, 75, 10), // "cellNumber"
QT_MOC_LITERAL(10, 86, 13), // "setCellNumber"
QT_MOC_LITERAL(11, 100, 1), // "s"
QT_MOC_LITERAL(12, 102, 8), // "interval"
QT_MOC_LITERAL(13, 111, 11), // "setInterval"
QT_MOC_LITERAL(14, 123, 4), // "msec"
QT_MOC_LITERAL(15, 128, 11), // "masterColor"
QT_MOC_LITERAL(16, 140, 14), // "setMasterColor"
QT_MOC_LITERAL(17, 155, 5), // "color"
QT_MOC_LITERAL(18, 161, 4), // "dump"
QT_MOC_LITERAL(19, 166, 7), // "setDump"
QT_MOC_LITERAL(20, 174, 4), // "data"
QT_MOC_LITERAL(21, 179, 9), // "paintGrid"
QT_MOC_LITERAL(22, 189, 9), // "QPainter&"
QT_MOC_LITERAL(23, 199, 1), // "p"
QT_MOC_LITERAL(24, 201, 13), // "paintUniverse"
QT_MOC_LITERAL(25, 215, 13) // "newGeneration"

    },
    "GameWidget\0environmentChanged\0\0ok\0"
    "gameEnds\0startGame\0number\0stopGame\0"
    "clear\0cellNumber\0setCellNumber\0s\0"
    "interval\0setInterval\0msec\0masterColor\0"
    "setMasterColor\0color\0dump\0setDump\0"
    "data\0paintGrid\0QPainter&\0p\0paintUniverse\0"
    "newGeneration"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       4,    1,  102,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,  105,    2, 0x0a /* Public */,
       5,    0,  108,    2, 0x2a /* Public | MethodCloned */,
       7,    0,  109,    2, 0x0a /* Public */,
       8,    0,  110,    2, 0x0a /* Public */,
       9,    0,  111,    2, 0x0a /* Public */,
      10,    1,  112,    2, 0x0a /* Public */,
      12,    0,  115,    2, 0x0a /* Public */,
      13,    1,  116,    2, 0x0a /* Public */,
      15,    0,  119,    2, 0x0a /* Public */,
      16,    1,  120,    2, 0x0a /* Public */,
      18,    0,  123,    2, 0x0a /* Public */,
      19,    1,  124,    2, 0x0a /* Public */,
      21,    1,  127,    2, 0x08 /* Private */,
      24,    1,  130,    2, 0x08 /* Private */,
      25,    0,  133,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::QColor,
    QMetaType::Void, QMetaType::QColor,   17,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void,

       0        // eod
};

void GameWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->environmentChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->gameEnds((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->startGame((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 3: _t->startGame(); break;
        case 4: _t->stopGame(); break;
        case 5: _t->clear(); break;
        case 6: { int _r = _t->cellNumber();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->setCellNumber((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 8: { int _r = _t->interval();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->setInterval((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: { QColor _r = _t->masterColor();
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->setMasterColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 12: { QString _r = _t->dump();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->setDump((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->paintGrid((*reinterpret_cast< QPainter(*)>(_a[1]))); break;
        case 15: _t->paintUniverse((*reinterpret_cast< QPainter(*)>(_a[1]))); break;
        case 16: _t->newGeneration(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GameWidget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameWidget::environmentChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GameWidget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameWidget::gameEnds)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GameWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_GameWidget.data,
    qt_meta_data_GameWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GameWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GameWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void GameWidget::environmentChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameWidget::gameEnds(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
