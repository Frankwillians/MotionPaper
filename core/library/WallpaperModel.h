#pragma once

#include <QAbstractListModel>
#include <QStringList>

struct WallpaperItem {
    QString title;
    QString filePath;
    QString thumbPath;
};

class WallpaperModel : public QAbstractListModel {
    Q_OBJECT

public:
    enum Roles {
        TitleRole = Qt::UserRole + 1,
        FilePathRole,
        ThumbPathRole
    };

    explicit WallpaperModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    void setItems(const QList<WallpaperItem> &items);

private:
    QList<WallpaperItem> m_items;
};