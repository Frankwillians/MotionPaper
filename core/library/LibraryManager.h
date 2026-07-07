#pragma once

#include <QObject>
#include <QString>

#include "core/library/WallpaperModel.h"

class LibraryManager : public QObject {
    Q_OBJECT
    Q_PROPERTY(WallpaperModel* model READ model CONSTANT)
    Q_PROPERTY(QString searchQuery READ searchQuery WRITE setSearchQuery NOTIFY searchQueryChanged)

public:
    explicit LibraryManager(QObject *parent = nullptr);

    WallpaperModel* model();

    QString searchQuery() const;
    void setSearchQuery(const QString &query);

    Q_INVOKABLE bool importVideo(const QString &fileUrl);
    Q_INVOKABLE bool deleteVideo(const QString &filePath);
    Q_INVOKABLE bool deleteWallpaper(const QString &videoPath);
    Q_INVOKABLE bool openVideo(const QString &filePath);
    Q_INVOKABLE void reload();

signals:
    void searchQueryChanged();

private:
    bool generateThumbnail(const QString &videoPath, const QString &thumbPath);
    void applyFilter();

private:
    QString m_basePath;
    QString m_wallpapersPath;
    QString m_thumbsPath;
    QString m_searchQuery;

    QList<WallpaperItem> m_allItems;
    WallpaperModel m_model;
};