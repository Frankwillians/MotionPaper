#include "LibraryManager.h"

#include <QDebug>
#include <QDesktopServices>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QProcess>
#include <QStandardPaths>
#include <QUrl>

LibraryManager::LibraryManager(QObject *parent)
    : QObject(parent)
{
    m_basePath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    m_wallpapersPath = m_basePath + "/Wallpapers";
    m_thumbsPath = m_basePath + "/Thumbs";

    QDir().mkpath(m_wallpapersPath);
    QDir().mkpath(m_thumbsPath);

    qDebug() << "LivePaper base path:" << m_basePath;

    reload();
}

WallpaperModel* LibraryManager::model()
{
    return &m_model;
}

QString LibraryManager::searchQuery() const
{
    return m_searchQuery;
}

void LibraryManager::setSearchQuery(const QString &query)
{
    if (m_searchQuery == query)
        return;

    m_searchQuery = query;
    emit searchQueryChanged();

    applyFilter();
}

void LibraryManager::reload()
{
    QDir dir(m_wallpapersPath);

    const QStringList filters = {
        "*.mp4", "*.webm", "*.mkv", "*.mov", "*.avi"
    };

    const QStringList files = dir.entryList(filters, QDir::Files, QDir::Name);

    m_allItems.clear();

    for (const QString &file : files) {
        QFileInfo info(m_wallpapersPath + "/" + file);

        const QString title = info.completeBaseName();
        const QString videoPath = info.absoluteFilePath();
        const QString thumbPath = m_thumbsPath + "/" + title + ".jpg";

        if (!QFile::exists(thumbPath)) {
            generateThumbnail(videoPath, thumbPath);
        }

        m_allItems.append({
            title,
            videoPath,
            QFile::exists(thumbPath) ? "file://" + thumbPath : ""
        });
    }

    applyFilter();

    qDebug() << "Wallpapers carregados:" << files;
}

void LibraryManager::applyFilter()
{
    if (m_searchQuery.trimmed().isEmpty()) {
        m_model.setItems(m_allItems);
        return;
    }

    QList<WallpaperItem> filtered;
    const QString query = m_searchQuery.trimmed().toLower();

    for (const WallpaperItem &item : m_allItems) {
        if (item.title.toLower().contains(query)) {
            filtered.append(item);
        }
    }

    m_model.setItems(filtered);
}

bool LibraryManager::importVideo(const QString &fileUrl)
{
    QUrl url(fileUrl);
    QString sourcePath = url.isLocalFile() ? url.toLocalFile() : fileUrl;

    QFileInfo info(sourcePath);

    if (!info.exists() || !info.isFile()) {
        qDebug() << "Arquivo inválido:" << sourcePath;
        return false;
    }

    const QString destinationPath = m_wallpapersPath + "/" + info.fileName();

    if (QFile::exists(destinationPath))
        QFile::remove(destinationPath);

    const bool ok = QFile::copy(sourcePath, destinationPath);

    if (ok)
        reload();

    return ok;
}

bool LibraryManager::deleteVideo(const QString &filePath)
{
    return deleteWallpaper(filePath);
}

bool LibraryManager::deleteWallpaper(const QString &videoPath)
{
    if (videoPath.isEmpty())
        return false;

    QFileInfo info(videoPath);

    if (!info.exists())
        return false;

    const QString thumb = m_thumbsPath + "/" + info.completeBaseName() + ".jpg";

    QFile::remove(videoPath);

    if (QFile::exists(thumb))
        QFile::remove(thumb);

    reload();

    return true;
}

bool LibraryManager::openVideo(const QString &filePath)
{
    if (filePath.isEmpty())
        return false;

    QFileInfo info(filePath);

    if (!info.exists())
        return false;

    return QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
}

bool LibraryManager::generateThumbnail(const QString &videoPath, const QString &thumbPath)
{
    QStringList args;
    args << "-y";
    args << "-ss" << "00:00:02";
    args << "-i" << videoPath;
    args << "-frames:v" << "1";
    args << "-q:v" << "2";
    args << thumbPath;

    QProcess ffmpeg;
    ffmpeg.start("ffmpeg", args);
    ffmpeg.waitForFinished(10000);

    return QFile::exists(thumbPath);
}