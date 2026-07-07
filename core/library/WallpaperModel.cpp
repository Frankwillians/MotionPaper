#include "WallpaperModel.h"

WallpaperModel::WallpaperModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int WallpaperModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_items.count();
}

QVariant WallpaperModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= m_items.count())
        return {};

    const WallpaperItem &item = m_items[index.row()];

    switch (role) {
    case TitleRole:
        return item.title;
    case FilePathRole:
        return item.filePath;
    case ThumbPathRole:
        return item.thumbPath;
    default:
        return {};
    }
}

QHash<int, QByteArray> WallpaperModel::roleNames() const
{
    return {
        {TitleRole, "title"},
        {FilePathRole, "filePath"},
        {ThumbPathRole, "thumbPath"}
    };
}

void WallpaperModel::setItems(const QList<WallpaperItem> &items)
{
    beginResetModel();
    m_items = items;
    endResetModel();
}