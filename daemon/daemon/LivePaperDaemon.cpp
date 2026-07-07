#include "LivePaperDaemon.h"

#include <QDebug>

#include "ipc/DBusServer.h"
#include "renderer/MpvRenderer.h"

LivePaperDaemon::LivePaperDaemon(QObject *parent)
    : QObject(parent)
{
}

LivePaperDaemon::~LivePaperDaemon()
{
    stop();
}

bool LivePaperDaemon::start()
{
    qInfo() << "Starting LivePaper daemon";

    m_renderer = std::make_unique<MpvRenderer>();

    if (!m_renderer->initialize()) {
        qCritical() << "Renderer initialization failed";
        return false;
    }

    m_dbusServer = std::make_unique<DBusServer>(this);

    if (!m_dbusServer->start()) {
        qCritical() << "D-Bus server failed";
        return false;
    }

    qInfo() << "LivePaper daemon running";
    return true;
}

void LivePaperDaemon::stop()
{
    if (m_renderer)
        m_renderer->stop();
}

QString LivePaperDaemon::ping()
{
    return "pong";
}

bool LivePaperDaemon::play(const QString &videoPath)
{
    qInfo() << "Daemon play:" << videoPath;

    if (!m_renderer)
        return false;

    return m_renderer->play(videoPath);
}

bool LivePaperDaemon::pausePlayback()
{
    qInfo() << "Daemon pause";

    if (!m_renderer)
        return false;

    m_renderer->pause();
    return true;
}

bool LivePaperDaemon::stopPlayback()
{
    qInfo() << "Daemon stop";

    if (!m_renderer)
        return false;

    m_renderer->stop();
    return true;
}