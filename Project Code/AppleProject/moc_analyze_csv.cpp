/****************************************************************************
** Meta object code from reading C++ file 'analyze_csv.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "analyze_csv.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'analyze_csv.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AnalyzeCSV_t {
    QByteArrayData data[10];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AnalyzeCSV_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AnalyzeCSV_t qt_meta_stringdata_AnalyzeCSV = {
    {
QT_MOC_LITERAL(0, 0, 10), // "AnalyzeCSV"
QT_MOC_LITERAL(1, 11, 19), // "on_load_btn_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 21), // "on_verify_btn_clicked"
QT_MOC_LITERAL(4, 54, 10), // "get_ui_ptr"
QT_MOC_LITERAL(5, 65, 15), // "Ui::AnalyzeCSV*"
QT_MOC_LITERAL(6, 81, 21), // "on_filter_btn_clicked"
QT_MOC_LITERAL(7, 103, 27), // "on_filter_btn_teach_clicked"
QT_MOC_LITERAL(8, 131, 23), // "on_filter_btn_2_clicked"
QT_MOC_LITERAL(9, 155, 34) // "on_filter_btn_presentation_cl..."

    },
    "AnalyzeCSV\0on_load_btn_clicked\0\0"
    "on_verify_btn_clicked\0get_ui_ptr\0"
    "Ui::AnalyzeCSV*\0on_filter_btn_clicked\0"
    "on_filter_btn_teach_clicked\0"
    "on_filter_btn_2_clicked\0"
    "on_filter_btn_presentation_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AnalyzeCSV[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       6,    0,   52,    2, 0x08 /* Private */,
       7,    0,   53,    2, 0x08 /* Private */,
       8,    0,   54,    2, 0x08 /* Private */,
       9,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AnalyzeCSV::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AnalyzeCSV *_t = static_cast<AnalyzeCSV *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_load_btn_clicked(); break;
        case 1: _t->on_verify_btn_clicked(); break;
        case 2: { Ui::AnalyzeCSV* _r = _t->get_ui_ptr();
            if (_a[0]) *reinterpret_cast< Ui::AnalyzeCSV**>(_a[0]) = _r; }  break;
        case 3: _t->on_filter_btn_clicked(); break;
        case 4: _t->on_filter_btn_teach_clicked(); break;
        case 5: _t->on_filter_btn_2_clicked(); break;
        case 6: _t->on_filter_btn_presentation_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject AnalyzeCSV::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AnalyzeCSV.data,
      qt_meta_data_AnalyzeCSV,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AnalyzeCSV::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AnalyzeCSV::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AnalyzeCSV.stringdata0))
        return static_cast<void*>(const_cast< AnalyzeCSV*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AnalyzeCSV::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
