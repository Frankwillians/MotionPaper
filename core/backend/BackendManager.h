#pragma once

#include <QObject>
#include <QString>

class BackendManager : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString currentBackend READ currentBackend CONSTANT)

public:
    explicit BackendManager(QObject *parent = nullptr);

    QString currentBackend() const;

    Q_INVOKABLE bool applyWallpaper(const QString &videoPath);

private:
    QString detectBackend() const;

private:
    QString m_currentBackend;
};