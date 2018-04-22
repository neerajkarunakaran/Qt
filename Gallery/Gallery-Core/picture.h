#ifndef PICTURE_H
#define PICTURE_H


#include <QUrl>
#include <QString>

#include "gallery-core_global.h"

class GALLERYCORESHARED_EXPORT Picture
{
public:
    Picture(const QString& filePath_ = "");
    Picture(const QUrl& fileUrl_);

    int id() const;
    void setId(int id_);

    int albumId() const;
    void setAlbumId(int albumId_);

    QUrl fileUrl() const;
    void setFileUrl(const QUrl& fileUrl_);
private:
    int      _mId;
    int      _mAlbumId;
    QUrl     _mFileUrl;
};


#endif // PICTURE_H
