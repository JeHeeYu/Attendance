#ifndef FILEEVENTMANAGER_H
#define FILEEVENTMANAGER_H

#include <QObject>
#include <QCoreApplication>
#include <QFile>
#include <QDir>
#include <QDebug>





#include <QtDebug>
#include <QSqlDatabase>
#include <QSqlQuery>

#include "Common/Singleton.h"

#define FILEEVENTMANAGER()      FileEventManager::Instance()

class FileEventManager : public QObject, public Singleton<FileEventManager>
{
    Q_OBJECT
public:
    explicit FileEventManager(QObject *parent = nullptr);

    bool CreateDirectory(QString folderName, QString folderPath = "");
    QString GetCurrentPath();
};

#endif // FILEEVENTMANAGER_H
