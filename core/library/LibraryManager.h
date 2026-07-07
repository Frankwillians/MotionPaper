#pragma once

#include <QObject>
#include <QString>

#include "core/library/WallpaperModel.h"

class LibraryManager : public QObject {
    Q_OBJECT
    Q_PROPERTY(WallpaperModel* model READ model CONSTANT)

public:
    explicit LibraryManager(QObject *parent = nullptr);

    WallpaperModel* model();

    Q_INVOKABLE bool importVideo(const QString &fileUrl);
    Q_INVOKABLE bool deleteVideo(const QString &filePath);
    Q_INVOKABLE bool deleteWallpaper(const QString &videoPath);
    Q_INVOKABLE bool openVideo(const QString &filePath);
    Q_INVOKABLE void reload();

private:
    bool generateThumbnail(const QString &videoPath, const QString &thumbPath);

private:
    QString m_basePath;
    QString m_wallpapersPath;
    QString m_thumbsPath;

    WallpaperModel m_model;
};