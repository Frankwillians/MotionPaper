#include "DBusServer.h"

#include <QDBusConnection>
#include <QDBusError>
#include <QDebug>

#include "daemon/LivePaperDaemon.h"

DBusServer::DBusServer(LivePaperDaemon *daemon, QObject *parent)
    : QObject(parent),
      m_daemon(daemon)
{
}

bool DBusServer::start()
{
    QDBusConnection bus = QDBusConnection::sessionBus();

    if (!bus.registerService("com.livepaper.Daemon")) {
        qCritical() << "Failed to register D-Bus service:"
                    << bus.lastError().message();
        return false;
    }

    if (!bus.registerObject(
            "/com/livepaper/Daemon",
            this,
            QDBusConnection::ExportAllSlots
        )) {
        qCritical() << "Failed to register D-Bus object:"
                    << bus.lastError().message();
        return false;
    }

    qInfo() << "D-Bus server started at com.livepaper.Daemon";
    return true;
}

QString DBusServer::Ping()
{
    return m_daemon->ping();
}

bool DBusServer::Play(const QString &videoPath)
{
    return m_daemon->play(videoPath);
}

bool DBusServer::Pause()
{
    return m_daemon->pausePlayback();
}

bool DBusServer::Stop()
{
    return m_daemon->stopPlayback();
}