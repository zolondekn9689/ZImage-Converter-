#include "imagebuilder.h"

ImageBuilder::ImageBuilder()
{
    directory = "";
    info = nullptr;
}

ImageBuilder::~ImageBuilder()
{
    if (info != nullptr) {
        delete info;
    }
}


void ImageBuilder::BuildPng(QString name, QString dest)
{
    info = new QFileInfo(name);
    SetDirectory(name, dest);

    QImage img(name);

    // Use to store new file name and directory.
    QString newFilePath;
    QString newDir;
    newDir = directory + "\\PNG";
    newFilePath = newDir + "\\" + info->baseName() + ".png";

    // Check if the directory exists.
    if (!QDir(newDir).exists())
        QDir().mkdir(newDir);

    //img.convertToFormat(QImage::Format_RGB32);

    img.save(newFilePath);

}


void ImageBuilder::BuildJpg(QString name, QString dest)
{
    info = new QFileInfo(name);
    SetDirectory(name, dest);

    QImage img(name);

    // Use to store new file name and directory.
    QString newFilePath;
    QString newDir;
    newDir = directory + "\\JPG";
    newFilePath = newDir + "\\" + info->baseName() + ".jpg";

    // Check if the directory exists.
    if (!QDir(newDir).exists())
        QDir().mkdir(newDir);

    //img.convertToFormat(QImage::Format_RGB32);

    img.save(newFilePath);
}

void ImageBuilder::BuildTIF(QString name, QString dest)
{
    info = new QFileInfo(name);
    SetDirectory(name, dest);

    QImage img(name);

    // Use to store new file name and directory.
    QString newFilePath;
    QString newDir;
    newDir = directory + "\\TIF";
    newFilePath = newDir + "\\" + info->baseName() + ".tif";

    // Check if the directory exists.
    if (!QDir(newDir).exists())
        QDir().mkdir(newDir);

    //img.convertToFormat(QImage::Format_RGB32);

    img.save(newFilePath);

}

void ImageBuilder::Message(QString info)
{
    QMessageBox b;
    b.setText(info);
    b.exec();

}

void ImageBuilder::SetDirectory(QString name, QString dest)
{
    // Assume predefined location.
    if (this->directory == "")
    {
        directory = info->absolutePath();

    } else {
        // Store in defined location.
        directory = dest;
    }
}
