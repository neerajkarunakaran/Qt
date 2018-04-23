
#include "albummodel.h"

AlbumModel::AlbumModel(QObject* parent_) :
    QAbstractListModel(parent_),
    _mDb(DatabaseManager::instance()),
    _mAlbums(_mDb.albumDao.albums())
{
}

QModelIndex AlbumModel::addAlbum(const Album &album_)
{
    int rowIndex = rowCount();
    beginInsertRows(QModelIndex(), rowIndex, rowIndex);
    std::unique_ptr<Album> newAlbum(new Album(album_));
    _mDb.albumDao.addAlbum(*newAlbum);
    _mAlbums->push_back(std::move(newAlbum));
    endInsertRows();
    return index(rowIndex, 0);
}

int AlbumModel::rowCount(const QModelIndex &parent_) const
{
    return _mAlbums->size();
}

QVariant AlbumModel::data(const QModelIndex &index_, int role_) const
{
    if (!isIndexValid(index_))
    {
        return QVariant();
    }
    const Album& album = *_mAlbums->at(index_.row());

    switch (role_)
    {
        case Roles::IdRole:
            return album.id();

        case Roles::NameRole:
        case Qt::DisplayRole:
            return album.name();

        default:
            return QVariant();
    }
}

bool AlbumModel::setData(const QModelIndex &index_, const QVariant &value_, int role_)
{
    if (!isIndexValid(index_) || role_ != Roles::NameRole)
    {
        return false;
    }
    Album& album = *_mAlbums->at(index_.row());
    album.setName(value_.toString());
    _mDb.albumDao.updateAlbum(album);
    emit dataChanged(index_, index_);
    return true;
}

bool AlbumModel::removeRows(int row_, int count_, const QModelIndex &parent_)
{
    if (row_ < 0 || row_ >= rowCount() || count_ < 0 || (row_ + count_) > rowCount())
    {
        return false;
    }
    beginRemoveRows(parent_, row_, row_ + count_ - 1);
    int countLeft = count_;
    while (countLeft--)
    {
        const Album& album = *_mAlbums->at(row_ + countLeft);
        _mDb.albumDao.removeAlbum(album.id());
    }
    _mAlbums->erase(_mAlbums->begin() + row_, _mAlbums->begin() + row_ + count_);
    endRemoveRows();
    return true;
}

QHash<int, QByteArray> AlbumModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Roles::IdRole] = "id";
    roles[Roles::NameRole] = "name";
    return roles;
}

bool AlbumModel::isIndexValid(const QModelIndex &index_) const
{

}

