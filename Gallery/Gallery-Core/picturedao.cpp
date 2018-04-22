#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "picturedao.h"
void PictureDao::init() const
{
    if (!mDatabase.tables().contains("pictures")) {
        QSqlQuery query(mDatabase);
        query.exec(QString("CREATE TABLE pictures")
        + " (id INTEGER PRIMARY KEY AUTOINCREMENT, "
        + "album_id INTEGER, "
        + "url TEXT)");
    }
}

void PictureDao::addPictureInAlbum(int albumId, Picture &picture) const
{

}

void PictureDao::removePicture(int id) const
{

}

void PictureDao::removePicturesForAlbum(int albumId) const
{

}

QVector<Picture *> PictureDao::picturesForAlbum(int albumId) const
{

}
