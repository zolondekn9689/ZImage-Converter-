#include "tifimage.h"

TifImage::TifImage() : AbstractImage("tif", "TIF")
{

}

void TifImage::Build(QString absoluteFileName)
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


    img.save(newFilePath);
}
