#include "picturemodel.h"



PictureModel::PictureModel(const AlbumModel &albumModel_, QObject *parent_)
    :QAbstractListModel(parent_),
    _mDb(DatabaseManager::instance()),
    _mAlbumId(-1),
    _mPictures(new std::vector<std::unique_ptr<Picture>>())
{
    connect(&albumModel_, &AlbumModel::rowsRemoved,
                this, &PictureModel::deletePicturesForAlbum);
}

QModelIndex PictureModel::addPicture(const Picture &picture_)
{

}

int PictureModel::rowCount(const QModelIndex &parent_) const
{

}

QVariant PictureModel::data(const QModelIndex &index_, int role_) const
{

}

bool PictureModel::removeRows(int row_, int count_, const QModelIndex &parent_)
{

}

void PictureModel::setAlbumId(int albumId_)
{
    beginResetModel();
    _mAlbumId = albumId_;
    loadPictures(_mAlbumId);
    endResetModel();
}

void PictureModel::clearAlbum()
{

}

void PictureModel::deletePicturesForAlbum()
{

}

void PictureModel::loadPictures(int albumId_)
{
    if (albumId_ <= 0)
    {
        _mPictures.reset(new std::vector<std::unique_ptr<Picture>>());
        return;
    }
    _mPictures = _mDb.pictureDao.picturesForAlbum(albumId_);
}

bool PictureModel::isIndexValid(const QModelIndex &index_) const
{

}
