#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "albumdao.h"
#include "picturedao.h"

#include <QString>

class QSqlDatabase;

const QString DATABASE_FILENAME = "gallery.db";

class DatabaseManager
{
public:
    static DatabaseManager& instance();
    ~DatabaseManager();

public :
    const AlbumDao albumDao;
    const PictureDao pictureDao;

protected:
    DatabaseManager(const QString& path_ = DATABASE_FILENAME);
    DatabaseManager& operator=(const DatabaseManager& rhs_);

private:
    QSqlDatabase* _mDatabase;
};


#endif // DATABASEMANAGER_H
