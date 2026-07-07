#pragma once

#include <QObject>

class LivePaperDaemon;

class DBusServer : public QObject {
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.livepaper.Daemon")

public:
    explicit DBusServer(LivePaperDaemon *daemon, QObject *parent = nullptr);

    bool start();

public slots:
    Q_SCRIPTABLE QString Ping();
    Q_SCRIPTABLE bool Play(const QString &videoPath);
    Q_SCRIPTABLE bool Pause();
    Q_SCRIPTABLE bool Stop();

private:
    LivePaperDaemon *m_daemon;
};