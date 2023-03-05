#ifndef FILEEVENTMANAGER_H
#define FILEEVENTMANAGER_H

#include <QObject>
#include <QCoreApplication>
#include <QFile>
#include <QDir>
#include <QDebug>

#include "Common/Singleton.h"

#define DATABASE_FOLDER_NAME        "DB"

#define FILEEVENTMANAGER()      FileEventManager::Instance()

class FileEventManager : public QObject, public Singleton<FileEventManager>
{
    Q_OBJECT
public:
    explicit FileEventManager(QObject *parent = nullptr);

    void FolderInit();
    bool CreateDirectory(QString folderName, QString folderPath = "");
    QString GetCurrentPath() const;
};

#endif // FILEEVENTMANAGER_H
