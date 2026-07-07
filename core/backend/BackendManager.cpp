#include "BackendManager.h"

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

    if (m_currentBackend == "GNOME Wayland") {
    QStringList args;
    args << "call";
    args << "--session";
    args << "--dest" << "org.gnome.Shell";
    args << "--object-path" << "/com/livepaper/Backend";
    args << "--method" << "com.livepaper.Backend.ApplyWallpaper";
    args << videoPath;

    bool ok = QProcess::startDetached("gdbus", args);

    qDebug() << "GNOME Wayland extension call:" << ok;

    return ok;
}

    if (m_currentBackend == "X11") {
        QProcess::startDetached("pkill", {"-f", "livepaper-wallpaper-mpv"});

        QStringList args;
        args << "--title=livepaper-wallpaper-mpv";
        args << "--wid=0";
        args << "--loop";
        args << "--no-audio";
        args << "--no-border";
        args << "--fullscreen";
        args << "--panscan=1.0";
        args << videoPath;

        bool ok = QProcess::startDetached("mpv", args);

        qDebug() << "Started X11 wallpaper mpv:" << ok;

        return ok;
    }

    qDebug() << "Backend not implemented yet.";
    return false;
}