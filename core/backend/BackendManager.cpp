#include "BackendManager.h"

#include <QDebug>
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

    if (videoPath.isEmpty()) {
        qDebug() << "No video selected.";
        return false;
    }

    if (m_currentBackend == "GNOME Wayland") {
        qDebug() << "GNOME Wayland requires a GNOME Shell extension backend.";
        return false;
    }

    qDebug() << "Backend not implemented yet.";
    return false;
}