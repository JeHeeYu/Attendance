#include "fileeventmanager.h"

FileEventManager::FileEventManager(QObject *parent) : QObject (parent)
{
}

bool FileEventManager::CreateDirectory(QString folderName, QString folderPath)
{
    qDebug() << "[" << Q_FUNC_INFO << "]" << " folderName : " << folderName << " folderPath : " << folderPath;


    QDir directory(folderName);

    if(directory.exists()) {
        qDebug() << "Folder Exists";

        return true;
    }

    else {
        if(folderPath != "") {
            if(directory.mkpath(folderPath)) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            // Current Path
            if(directory.mkpath(".")) {
                return true;
            }
            else {
                return false;
            }
        }
    }
}

QString FileEventManager::GetCurrentPath()
{
    QDir path;

    return path.currentPath() + "/";
}
