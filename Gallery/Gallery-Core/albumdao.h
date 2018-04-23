#ifndef ALBUMDAO_H
#define ALBUMDAO_H
#include <memory>
#include <vector>

#include <QSqlDatabase>

#include "album.h"

//class QSqlDatabase;
//class Album;

class AlbumDao
{
public:
    AlbumDao(QSqlDatabase& database_);
    void init() const;

    void addAlbum(Album &album_) const;
    void updateAlbum(const Album& album_) const;
    void removeAlbum(int id_) const;
    std::unique_ptr<std::vector<std::unique_ptr<Album>>> albums() const;

private:
    QSqlDatabase& _mDatabase;
};


#endif // ALBUMDAO_H
