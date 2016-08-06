/****************************************************************************
** Meta object code from reading C++ file 'inodemanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qt/inodemanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'inodemanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_InodeManager_t {
    QByteArrayData data[18];
    char stringdata[335];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_InodeManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_InodeManager_t qt_meta_stringdata_InodeManager = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 14),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 14),
QT_MOC_LITERAL(4, 44, 5),
QT_MOC_LITERAL(5, 50, 4),
QT_MOC_LITERAL(6, 55, 7),
QT_MOC_LITERAL(7, 63, 10),
QT_MOC_LITERAL(8, 74, 28),
QT_MOC_LITERAL(9, 103, 23),
QT_MOC_LITERAL(10, 127, 21),
QT_MOC_LITERAL(11, 149, 26),
QT_MOC_LITERAL(12, 176, 22),
QT_MOC_LITERAL(13, 199, 21),
QT_MOC_LITERAL(14, 221, 25),
QT_MOC_LITERAL(15, 247, 24),
QT_MOC_LITERAL(16, 272, 23),
QT_MOC_LITERAL(17, 296, 37)
    },
    "InodeManager\0updateNodeList\0\0"
    "updateRushNode\0alias\0addr\0privkey\0"
    "collateral\0on_copyAddressButton_clicked\0"
    "on_createButton_clicked\0on_editButton_clicked\0"
    "on_getConfigButton_clicked\0"
    "on_startButton_clicked\0on_stopButton_clicked\0"
    "on_startAllButton_clicked\0"
    "on_stopAllButton_clicked\0"
    "on_removeButton_clicked\0"
    "on_tableWidget_2_itemSelectionChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InodeManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a,
       3,    4,   75,    2, 0x0a,
       8,    0,   84,    2, 0x08,
       9,    0,   85,    2, 0x08,
      10,    0,   86,    2, 0x08,
      11,    0,   87,    2, 0x08,
      12,    0,   88,    2, 0x08,
      13,    0,   89,    2, 0x08,
      14,    0,   90,    2, 0x08,
      15,    0,   91,    2, 0x08,
      16,    0,   92,    2, 0x08,
      17,    0,   93,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    4,    5,    6,    7,
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

void InodeManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        InodeManager *_t = static_cast<InodeManager *>(_o);
        switch (_id) {
        case 0: _t->updateNodeList(); break;
        case 1: _t->updateRushNode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 2: _t->on_copyAddressButton_clicked(); break;
        case 3: _t->on_createButton_clicked(); break;
        case 4: _t->on_editButton_clicked(); break;
        case 5: _t->on_getConfigButton_clicked(); break;
        case 6: _t->on_startButton_clicked(); break;
        case 7: _t->on_stopButton_clicked(); break;
        case 8: _t->on_startAllButton_clicked(); break;
        case 9: _t->on_stopAllButton_clicked(); break;
        case 10: _t->on_removeButton_clicked(); break;
        case 11: _t->on_tableWidget_2_itemSelectionChanged(); break;
        default: ;
        }
    }
}

const QMetaObject InodeManager::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_InodeManager.data,
      qt_meta_data_InodeManager,  qt_static_metacall, 0, 0}
};


const QMetaObject *InodeManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InodeManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_InodeManager.stringdata))
        return static_cast<void*>(const_cast< InodeManager*>(this));
    return QWidget::qt_metacast(_clname);
}

int InodeManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
