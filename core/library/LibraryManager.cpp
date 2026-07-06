#include "LibraryManager.h"

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QStandardPaths>
#include <QUrl>

LibraryManager::LibraryManager(QObject *parent)
    : QObject(parent)
{
    const QString base = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    m_libraryPath = base + "/Wallpapers";

    qDebug() << "MotionPaper library path:" << m_libraryPath;

    QDir().mkpath(m_libraryPath);
    reload();
}

QStringList LibraryManager::wallpapers() const
{
    return m_wallpapers;
}

void LibraryManager::reload()
{
    QDir dir(m_libraryPath);

    const QStringList filters = {
        "*.mp4", "*.webm", "*.mkv", "*.mov", "*.avi"
    };

    m_wallpapers = dir.entryList(filters, QDir::Files, QDir::Name);

    qDebug() << "Wallpapers carregados:" << m_wallpapers;

    emit wallpapersChanged();
}

bool LibraryManager::importVideo(const QString &fileUrl)
{
    qDebug() << "Import recebido:" << fileUrl;

    QUrl url(fileUrl);
    QString sourcePath;

    if (url.isValid() && url.isLocalFile()) {
        sourcePath = url.toLocalFile();
    } else {
        sourcePath = fileUrl;
    }

    qDebug() << "Source path:" << sourcePath;
    qDebug() << "Library path:" << m_libraryPath;

    QFileInfo info(sourcePath);

    if (!info.exists()) {
        qDebug() << "ERRO: arquivo não existe.";
        return false;
    }

    if (!info.isFile()) {
        qDebug() << "ERRO: caminho não é arquivo.";
        return false;
    }

    QDir().mkpath(m_libraryPath);

    const QString destinationPath = m_libraryPath + "/" + info.fileName();

    qDebug() << "Destination:" << destinationPath;

    if (QFile::exists(destinationPath)) {
        qDebug() << "Arquivo já existe. Removendo antigo.";
        QFile::remove(destinationPath);
    }

    const bool ok = QFile::copy(sourcePath, destinationPath);

    qDebug() << "Copy OK:" << ok;

    if (ok) {
        reload();
    }

    return ok;
}