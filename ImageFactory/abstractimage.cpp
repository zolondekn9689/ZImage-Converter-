#include "abstractimage.h"

AbstractImage::AbstractImage(QString fileExt, QString folderName)
{
    this->fileExtension = fileExt;
    this->dotFileExtension = "." + fileExt;
    this->folderName = folderName;
}

void AbstractImage::BuildMessage(QString message)
{
    QMessageBox b;
    b.setText(message);
    b.exec();
}

void AbstractImage::Build(QString absoluteFileName)
{
    QFileInfo info(absoluteFileName);

    // Build an image
    QImage img(absoluteFileName);

    // Use to store new file name and directory.
    QString newDir = info.absolutePath() + GetSlashFolderName();
    QString newFilePath = BuildSavedPath(newDir, info.baseName());

    // Check if the directory exists.
    if (!QDir(newDir).exists())
        QDir().mkdir(newDir);

    //img.convertToFormat(QImage::Format_RGB32);

    img.save(newFilePath);
}

QString AbstractImage::GetFolderName()
{
    return folderName;
}

QString AbstractImage::GetFileExtension()
{
    return this->fileExtension;
}

QString AbstractImage::GetDotFileExtension() {
    return this->dotFileExtension;
}


QString AbstractImage::GetSlashFolderName() {
    return "/" + this->folderName;
}

QString AbstractImage::BuildSavedPath(QString dir, QString filename)
{
    return dir + "/" + filename + GetDotFileExtension();
}
