#pragma once
#include <QObject>
#include <QStringList>

class LibraryManager : public QObject {
    Q_OBJECT
    Q_PROPERTY(QStringList wallpapers READ wallpapers NOTIFY wallpapersChanged)

public:
    explicit LibraryManager(QObject *parent = nullptr);

    QStringList wallpapers() const;

    Q_INVOKABLE bool importVideo(const QString &fileUrl);
    Q_INVOKABLE void reload();

signals:
    void wallpapersChanged();

private:
    QString m_libraryPath;
    QStringList m_wallpapers;
};