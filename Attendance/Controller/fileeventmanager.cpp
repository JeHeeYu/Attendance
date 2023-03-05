#include "fileeventmanager.h"

FileEventManager::FileEventManager(QObject *parent) : QObject (parent)
{
    FolderInit();
}

void FileEventManager::FolderInit()
{
    CreateDirectory(DATABASE_FOLDER_NAME);
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

QString FileEventManager::GetCurrentPath() const
{
    QDir path;

    return path.currentPath() + "/";
}
