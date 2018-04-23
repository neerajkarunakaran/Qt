#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "picturedao.h"
void PictureDao::init() const
{
    if (!_mDatabase.tables().contains("pictures")) {
        QSqlQuery query(_mDatabase);
        query.exec(QString("CREATE TABLE pictures")
        + " (id INTEGER PRIMARY KEY AUTOINCREMENT, "
        + "album_id INTEGER, "
        + "url TEXT)");
    }
}

void PictureDao::addPictureInAlbum(int albumId_, Picture &picture_) const
{

}

void PictureDao::removePicture(int id_) const
{

}

void PictureDao::removePicturesForAlbum(int albumId_) const
{

}

std::unique_ptr<std::vector<std::unique_ptr<Picture>>> PictureDao::picturesForAlbum(int albumId_) const
{

}
