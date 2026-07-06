/****************************************************************************
** Meta object code from reading C++ file 'LibraryManager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../core/library/LibraryManager.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LibraryManager.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_LibraryManager_t {
    uint offsetsAndSizes[14];
    char stringdata0[15];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[8];
    char stringdata5[7];
    char stringdata6[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_LibraryManager_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_LibraryManager_t qt_meta_stringdata_LibraryManager = {
    {
        QT_MOC_LITERAL(0, 14),  // "LibraryManager"
        QT_MOC_LITERAL(15, 17),  // "wallpapersChanged"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 11),  // "importVideo"
        QT_MOC_LITERAL(46, 7),  // "fileUrl"
        QT_MOC_LITERAL(54, 6),  // "reload"
        QT_MOC_LITERAL(61, 10)   // "wallpapers"
    },
    "LibraryManager",
    "wallpapersChanged",
    "",
    "importVideo",
    "fileUrl",
    "reload",
    "wallpapers"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_LibraryManager[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       1,   37, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x06,    2 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   33,    2, 0x02,    3 /* Public */,
       5,    0,   36,    2, 0x02,    5 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Bool, QMetaType::QString,    4,
    QMetaType::Void,

 // properties: name, type, flags
       6, QMetaType::QStringList, 0x00015001, uint(0), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject LibraryManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_LibraryManager.offsetsAndSizes,
    qt_meta_data_LibraryManager,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_LibraryManager_t,
        // property 'wallpapers'
        QtPrivate::TypeAndForceComplete<QStringList, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<LibraryManager, std::true_type>,
        // method 'wallpapersChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'importVideo'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'reload'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void LibraryManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LibraryManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->wallpapersChanged(); break;
        case 1: { bool _r = _t->importVideo((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->reload(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LibraryManager::*)();
            if (_t _q_method = &LibraryManager::wallpapersChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<LibraryManager *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QStringList*>(_v) = _t->wallpapers(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *LibraryManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LibraryManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LibraryManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int LibraryManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void LibraryManager::wallpapersChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
