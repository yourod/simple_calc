/****************************************************************************
** Meta object code from reading C++ file 'calc.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CALC_Git/calc.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CALC_t {
    QByteArrayData data[20];
    char stringdata0[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CALC_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CALC_t qt_meta_stringdata_CALC = {
    {
QT_MOC_LITERAL(0, 0, 4), // "CALC"
QT_MOC_LITERAL(1, 5, 14), // "clickFromDigit"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 4), // "text"
QT_MOC_LITERAL(4, 26, 10), // "clickDigit"
QT_MOC_LITERAL(5, 37, 9), // "clickSign"
QT_MOC_LITERAL(6, 47, 7), // "clickCE"
QT_MOC_LITERAL(7, 55, 9), // "clickPlus"
QT_MOC_LITERAL(8, 65, 10), // "clickMinus"
QT_MOC_LITERAL(9, 76, 8), // "clickDiv"
QT_MOC_LITERAL(10, 85, 9), // "clickMult"
QT_MOC_LITERAL(11, 95, 7), // "clickEq"
QT_MOC_LITERAL(12, 103, 9), // "clickBack"
QT_MOC_LITERAL(13, 113, 12), // "clickPercent"
QT_MOC_LITERAL(14, 126, 8), // "clickDot"
QT_MOC_LITERAL(15, 135, 11), // "clickSquare"
QT_MOC_LITERAL(16, 147, 10), // "changeSize"
QT_MOC_LITERAL(17, 158, 13), // "keyPressEvent"
QT_MOC_LITERAL(18, 172, 10), // "QKeyEvent*"
QT_MOC_LITERAL(19, 183, 5) // "event"

    },
    "CALC\0clickFromDigit\0\0text\0clickDigit\0"
    "clickSign\0clickCE\0clickPlus\0clickMinus\0"
    "clickDiv\0clickMult\0clickEq\0clickBack\0"
    "clickPercent\0clickDot\0clickSquare\0"
    "changeSize\0keyPressEvent\0QKeyEvent*\0"
    "event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CALC[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   92,    2, 0x0a /* Public */,
       5,    0,   93,    2, 0x0a /* Public */,
       6,    0,   94,    2, 0x0a /* Public */,
       7,    0,   95,    2, 0x0a /* Public */,
       8,    0,   96,    2, 0x0a /* Public */,
       9,    0,   97,    2, 0x0a /* Public */,
      10,    0,   98,    2, 0x0a /* Public */,
      11,    0,   99,    2, 0x0a /* Public */,
      12,    0,  100,    2, 0x0a /* Public */,
      13,    0,  101,    2, 0x0a /* Public */,
      14,    0,  102,    2, 0x0a /* Public */,
      15,    0,  103,    2, 0x0a /* Public */,
      16,    0,  104,    2, 0x0a /* Public */,
      17,    1,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,

       0        // eod
};

void CALC::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CALC *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clickFromDigit((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->clickDigit(); break;
        case 2: _t->clickSign(); break;
        case 3: _t->clickCE(); break;
        case 4: _t->clickPlus(); break;
        case 5: _t->clickMinus(); break;
        case 6: _t->clickDiv(); break;
        case 7: _t->clickMult(); break;
        case 8: _t->clickEq(); break;
        case 9: _t->clickBack(); break;
        case 10: _t->clickPercent(); break;
        case 11: _t->clickDot(); break;
        case 12: _t->clickSquare(); break;
        case 13: _t->changeSize(); break;
        case 14: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CALC::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CALC::clickFromDigit)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CALC::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CALC.data,
    qt_meta_data_CALC,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CALC::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CALC::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CALC.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CALC::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void CALC::clickFromDigit(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
