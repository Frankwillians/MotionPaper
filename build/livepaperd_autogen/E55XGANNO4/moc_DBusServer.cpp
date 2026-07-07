/****************************************************************************
** Meta object code from reading C++ file 'DBusServer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../daemon/ipc/DBusServer.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DBusServer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_DBusServer_t {
    uint offsetsAndSizes[18];
    char stringdata0[11];
    char stringdata1[16];
    char stringdata2[21];
    char stringdata3[5];
    char stringdata4[1];
    char stringdata5[5];
    char stringdata6[10];
    char stringdata7[6];
    char stringdata8[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_DBusServer_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_DBusServer_t qt_meta_stringdata_DBusServer = {
    {
        QT_MOC_LITERAL(0, 10),  // "DBusServer"
        QT_MOC_LITERAL(11, 15),  // "D-Bus Interface"
        QT_MOC_LITERAL(27, 20),  // "com.livepaper.Daemon"
        QT_MOC_LITERAL(48, 4),  // "Ping"
        QT_MOC_LITERAL(53, 0),  // ""
        QT_MOC_LITERAL(54, 4),  // "Play"
        QT_MOC_LITERAL(59, 9),  // "videoPath"
        QT_MOC_LITERAL(69, 5),  // "Pause"
        QT_MOC_LITERAL(75, 4)   // "Stop"
    },
    "DBusServer",
    "D-Bus Interface",
    "com.livepaper.Daemon",
    "Ping",
    "",
    "Play",
    "videoPath",
    "Pause",
    "Stop"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_DBusServer[] = {

 // content:
      10,       // revision
       0,       // classname
       1,   14, // classinfo
       4,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   40,    4, 0x4a,    1 /* Public | isScriptable */,
       5,    1,   41,    4, 0x4a,    2 /* Public | isScriptable */,
       7,    0,   44,    4, 0x4a,    4 /* Public | isScriptable */,
       8,    0,   45,    4, 0x4a,    5 /* Public | isScriptable */,

 // slots: parameters
    QMetaType::QString,
    QMetaType::Bool, QMetaType::QString,    6,
    QMetaType::Bool,
    QMetaType::Bool,

       0        // eod
};

Q_CONSTINIT const QMetaObject DBusServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DBusServer.offsetsAndSizes,
    qt_meta_data_DBusServer,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_DBusServer_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DBusServer, std::true_type>,
        // method 'Ping'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'Play'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'Pause'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'Stop'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void DBusServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DBusServer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { QString _r = _t->Ping();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->Play((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->Pause();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->Stop();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *DBusServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DBusServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DBusServer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DBusServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
