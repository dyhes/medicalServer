/****************************************************************************
** Meta object code from reading C++ file 'patientinfo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../patientinfo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'patientinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_patientInfo_t {
    QByteArrayData data[16];
    char stringdata0[274];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_patientInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_patientInfo_t qt_meta_stringdata_patientInfo = {
    {
QT_MOC_LITERAL(0, 0, 11), // "patientInfo"
QT_MOC_LITERAL(1, 12, 8), // "showmain"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8), // "showsign"
QT_MOC_LITERAL(4, 31, 23), // "on_btnSelectALL_clicked"
QT_MOC_LITERAL(5, 55, 20), // "on_btnDelete_clicked"
QT_MOC_LITERAL(6, 76, 20), // "on_btnInsert_clicked"
QT_MOC_LITERAL(7, 97, 19), // "on_btnQuery_clicked"
QT_MOC_LITERAL(8, 117, 20), // "on_btnUpdate_clicked"
QT_MOC_LITERAL(9, 138, 19), // "on_btnPrint_clicked"
QT_MOC_LITERAL(10, 158, 19), // "on_btnClear_clicked"
QT_MOC_LITERAL(11, 178, 17), // "on_btnEcg_clicked"
QT_MOC_LITERAL(12, 196, 24), // "on_btnEcgDiagram_clicked"
QT_MOC_LITERAL(13, 221, 18), // "on_btnSpO2_clicked"
QT_MOC_LITERAL(14, 240, 16), // "on_btnPR_clicked"
QT_MOC_LITERAL(15, 257, 16) // "on_btnHR_clicked"

    },
    "patientInfo\0showmain\0\0showsign\0"
    "on_btnSelectALL_clicked\0on_btnDelete_clicked\0"
    "on_btnInsert_clicked\0on_btnQuery_clicked\0"
    "on_btnUpdate_clicked\0on_btnPrint_clicked\0"
    "on_btnClear_clicked\0on_btnEcg_clicked\0"
    "on_btnEcgDiagram_clicked\0on_btnSpO2_clicked\0"
    "on_btnPR_clicked\0on_btnHR_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_patientInfo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

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

       0        // eod
};

void patientInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        patientInfo *_t = static_cast<patientInfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showmain(); break;
        case 1: _t->showsign(); break;
        case 2: _t->on_btnSelectALL_clicked(); break;
        case 3: _t->on_btnDelete_clicked(); break;
        case 4: _t->on_btnInsert_clicked(); break;
        case 5: _t->on_btnQuery_clicked(); break;
        case 6: _t->on_btnUpdate_clicked(); break;
        case 7: _t->on_btnPrint_clicked(); break;
        case 8: _t->on_btnClear_clicked(); break;
        case 9: _t->on_btnEcg_clicked(); break;
        case 10: _t->on_btnEcgDiagram_clicked(); break;
        case 11: _t->on_btnSpO2_clicked(); break;
        case 12: _t->on_btnPR_clicked(); break;
        case 13: _t->on_btnHR_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (patientInfo::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&patientInfo::showmain)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (patientInfo::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&patientInfo::showsign)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject patientInfo::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_patientInfo.data,
      qt_meta_data_patientInfo,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *patientInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *patientInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_patientInfo.stringdata0))
        return static_cast<void*>(const_cast< patientInfo*>(this));
    return QWidget::qt_metacast(_clname);
}

int patientInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void patientInfo::showmain()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void patientInfo::showsign()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
