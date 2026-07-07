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

void LibraryManager::reload()
{
    QDir dir(m_wallpapersPath);

    const QStringList filters = {
        "*.mp4", "*.webm", "*.mkv", "*.mov", "*.avi"
    };

    const QStringList files = dir.entryList(filters, QDir::Files, QDir::Name);
    QList<WallpaperItem> items;

    for (const QString &file : files) {
        QFileInfo info(m_wallpapersPath + "/" + file);

        const QString title = info.completeBaseName();
        const QString videoPath = info.absoluteFilePath();
        const QString thumbPath = m_thumbsPath + "/" + title + ".jpg";

        if (!QFile::exists(thumbPath)) {
            generateThumbnail(videoPath, thumbPath);
        }

        items.append({
            title,
            videoPath,
            QFile::exists(thumbPath) ? "file://" + thumbPath : ""
        });
    }

    m_model.setItems(items);
    qDebug() << "Wallpapers carregados:" << files;
}

bool LibraryManager::importVideo(const QString &fileUrl)
{
    qDebug() << "Import recebido:" << fileUrl;

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

    qDebug() << "Copy OK:" << ok;

    if (ok)
        reload();

    return ok;
}

bool LibraryManager::deleteVideo(const QString &filePath)
{
    if (filePath.isEmpty())
        return false;

    QFileInfo info(filePath);

    if (!info.exists()) {
        qDebug() << "Delete: arquivo não existe:" << filePath;
        return false;
    }

    const QString title = info.completeBaseName();
    const QString thumbPath = m_thumbsPath + "/" + title + ".jpg";

    bool videoDeleted = QFile::remove(filePath);

    if (QFile::exists(thumbPath))
        QFile::remove(thumbPath);

    qDebug() << "Delete video:" << filePath << videoDeleted;

    reload();
    return videoDeleted;
}

bool LibraryManager::openVideo(const QString &filePath)
{
    if (filePath.isEmpty())
        return false;

    QFileInfo info(filePath);

    if (!info.exists()) {
        qDebug() << "Open: arquivo não existe:" << filePath;
        return false;
    }

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

    const bool ok = QFile::exists(thumbPath);

    qDebug() << "Thumbnail:" << thumbPath << "OK:" << ok;

    return ok;
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