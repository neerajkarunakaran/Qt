#include "databasemanager.h"

#include <QSqlDatabase>

DatabaseManager& DatabaseManager::instance()
{
    static DatabaseManager singleton;
    return singleton;
}

DatabaseManager::DatabaseManager(const QString& path_) :
    _mDatabase(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE")))
    ,albumDao(*_mDatabase)
  , pictureDao(*_mDatabase)
{
    _mDatabase->setDatabaseName(path_);
    _mDatabase->open();
    albumDao.init();
}

DatabaseManager::~DatabaseManager()
{
    _mDatabase->close();
    delete _mDatabase;
}

