#pragma once

#include <QObject>
#include <memory>

#include "renderer/Renderer.h"

class DBusServer;

class LivePaperDaemon : public QObject {
    Q_OBJECT

public:
    explicit LivePaperDaemon(QObject *parent = nullptr);
    ~LivePaperDaemon();

    bool start();
    void stop();

    QString ping();
    bool play(const QString &videoPath);
    bool pausePlayback();
    bool stopPlayback();

private:
    std::unique_ptr<Renderer> m_renderer;
    std::unique_ptr<DBusServer> m_dbusServer;
};