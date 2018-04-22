#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "albumdao.h"
#include "databasemanager.h"

AlbumDao::AlbumDao(QSqlDatabase& database_) :
    _mDatabase(database_)
{
}

void AlbumDao::init() const
{
    if (!_mDatabase.tables().contains("albums")) {
        QSqlQuery query(_mDatabase);
        query.exec("CREATE TABLE albums (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT)");
    }
}


void AlbumDao::addAlbum(Album& album_) const
{
    QSqlQuery query(_mDatabase);
    query.prepare("INSERT INTO albums (name) VALUES (:name)");
    query.bindValue(":name", album_.name());
    query.exec();
    album.setId(query.lastInsertId().toInt());
}

void AlbumDao::updateAlbum(const Album &album_) const
{

}

void AlbumDao::removeAlbum(int id_) const
{

}

QVector<Album*> AlbumDao::albums() const
{
    QSqlQuery query("SELECT * FROM albums", _mDatabase);
    query.exec();
    QVector<Album*> list;
    while(query.next()) {
        Album* album = new Album();
        album->setId(query.value("id").toInt());
        album->setName(query.value("name").toString());
        list.append(album);
    }
    return list;
}
