#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

#include "Common/Singleton.h"
#include "fileeventmanager.h"

// SQL Query
#define CREATE_TABLE_STRING               "CREATE TABLE %1 (id int not null primary key);"
#define ADD_COLUMN_STRING                 "ALTER TABLE %1 ADD %2 %3;"

#define DATABASE_TYPE         "QSQLITE"
#define DATABASE_PATH         "DB/"

#define EMPLOYEE_DATABASE_NAME  "Employees.DB"

#define DATABASEMANAGER()       DatabaseManager::Instance()

class DatabaseManager : public QObject, public Singleton<DatabaseManager>
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = nullptr);

    QSqlError ConnectionDatabase();
    QSqlError CreateTable(QSqlDatabase &db, const QString tableName);
    QSqlError AddColumn(QSqlDatabase &db, const QString tableName, const QString columnName, const QString columnType);

    void QueryExec(QSqlDatabase &db, const QString& queryString);
    void QueryExec(QSqlDatabase &db, const QString& queryString, QVariantList& queryData);
};

#endif // DATABASEMANAGER_H
