#include "BackendManager.h"

#include <QCoreApplication>
#include <QDebug>
#include <QFileInfo>
#include <QProcess>
#include <QProcessEnvironment>

BackendManager::BackendManager(QObject *parent)
    : QObject(parent)
{
    m_currentBackend = detectBackend();
    qDebug() << "LivePaper backend:" << m_currentBackend;
}

QString BackendManager::currentBackend() const
{
    return m_currentBackend;
}

QString BackendManager::detectBackend() const
{
    const auto env = QProcessEnvironment::systemEnvironment();

    const QString session = env.value("XDG_SESSION_TYPE");
    const QString desktop = env.value("XDG_CURRENT_DESKTOP");

    if (session == "wayland" && desktop.contains("GNOME", Qt::CaseInsensitive))
        return "GNOME Wayland";

    if (desktop.contains("KDE", Qt::CaseInsensitive))
        return "KDE Plasma";

    if (session == "x11")
        return "X11";

    return "Unknown";
}

bool BackendManager::applyWallpaper(const QString &videoPath)
{
    qDebug() << "Apply requested:" << videoPath;
    qDebug() << "Backend:" << m_currentBackend;

    if (videoPath.isEmpty())
        return false;

    QFileInfo info(videoPath);
    if (!info.exists())
        return false;

    QStringList args;
    args << "call";
    args << "--session";
    args << "--dest" << "com.livepaper.Daemon";
    args << "--object-path" << "/com/livepaper/Daemon";
    args << "--method" << "com.livepaper.Daemon.Play";
    args << videoPath;

    bool ok = QProcess::startDetached("gdbus", args);

    qDebug() << "Sent Play command to livepaperd:" << ok;

    return ok;
}