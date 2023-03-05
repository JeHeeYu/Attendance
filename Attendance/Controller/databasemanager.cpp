#include "databasemanager.h"

DatabaseManager::DatabaseManager(QObject *parent) : QObject (parent)
{
}

QSqlError  DatabaseManager::ConnectionDatabase()
{
    QSqlError error;
    QSqlDatabase db = QSqlDatabase::addDatabase(DATABASE_TYPE);
    db.setDatabaseName(FILEEVENTMANAGER()->GetCurrentPath() + DATABASE_PATH + EMPLOYEE_DATABASE_NAME);
    if(!db.open()) {
        error = db.lastError();
        db = QSqlDatabase();
        qDebug() << "EmplyoeeDatabase Init Fail";
    }

    return error;
}

QSqlError DatabaseManager::CreateTable(QSqlDatabase &db, const QString tableName)
{
    QSqlError error;
    QSqlQuery query(db);

    QString queryString = CREATE_TABLE_STRING;

    query.prepare(queryString.arg(tableName));

    if (!query.exec()) {
        error = db.lastError();
        db = QSqlDatabase();
    }

    return error;
}

QSqlError DatabaseManager::AddColumn(QSqlDatabase &db, const QString tableName, const QString columnName, const QString columnType)
{
    QSqlError error;
    QSqlQuery query(db);

    QString queryString = ADD_COLUMN_STRING;

    query.prepare(queryString.arg(tableName).arg(columnName).arg(columnType));

    if (!query.exec()) {
        error = db.lastError();
        db = QSqlDatabase();
    }

    return error;
}

void DatabaseManager::QueryExec(QSqlDatabase &db, const QString &queryString)
{
    QSqlQuery query(db);
    query.prepare(queryString);
    query.exec();
}

void DatabaseManager::QueryExec(QSqlDatabase &db, const QString &queryString, QVariantList &queryData)
{
    QSqlQuery query(db);
    query.prepare(queryString);
    query.exec();

    while(query.next()) {
        QSqlRecord record = query.record();
        int count = record.count();
        QVariantMap map;

        for(int i = 0; i < count; i++) {
            //map[record.field(i).id()] = record.value(i);

        }

        queryData.push_back(map);
    }
}
