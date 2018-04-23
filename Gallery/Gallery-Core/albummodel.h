#ifndef ALBUMMODEL_H
#define ALBUMMODEL_H


#include <QAbstractListModel>
#include <QHash>
#include <vector>
#include <memory>

#include "gallery-core_global.h"
#include "album.h"
#include "databasemanager.h"

class GALLERYCORESHARED_EXPORT AlbumModel : public QAbstractListModel
{
    Q_OBJECT
public:

    enum Roles {
        IdRole = Qt::UserRole + 1,
        NameRole,
    };

    AlbumModel(QObject* parent_ = 0);

    QModelIndex addAlbum(const Album& album_);

    int rowCount(const QModelIndex& parent_ = QModelIndex()) const override;
    QVariant data(const QModelIndex& index_, int role_ = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index_, const QVariant& value_, int role_) override;
    bool removeRows(int row_, int count_, const QModelIndex& parent_) override;
    QHash<int, QByteArray> roleNames() const override;

private:
    bool isIndexValid(const QModelIndex& index_) const;

private:
    DatabaseManager& _mDb;
    std::unique_ptr<std::vector<std::unique_ptr<Album>>> _mAlbums;
};

#endif // ALBUMMODEL_H
