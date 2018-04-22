#include "picture.h"
Picture::Picture(const QString& filePath_) :
    Picture(QUrl::fromLocalFile(filePath_))
{
}

Picture::Picture(const QUrl& fileUrl_) :
    _mId(-1),
    _mAlbumId(-1),
    _mFileUrl(fileUrl)
{
}

int Picture::id() const
{
    return _mId;
}

void Picture::setId(int id_)
{
    _mId = id_;
}

int Picture::albumId() const
{
    return _mAlbumId;
}

void Picture::setAlbumId(int albumId_)
{
    _mAlbumId = albumId_;
}

QUrl Picture::fileUrl() const
{
    return _mFileUrl;
}

void Picture::setFileUrl(const QUrl& fileUrl_)
{
    _mFileUrl = fileUrl_;
}

