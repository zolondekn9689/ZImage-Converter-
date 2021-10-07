#ifndef IMAGEBUILDER_H
#define IMAGEBUILDER_H

#include <QString>
#include <QMessageBox>
#include <QFileDialog>
#include <QImage>
#include <QPixmap>
#include <QPixelFormat>
#include <QDirIterator>
#include <QImageReader>
#include <QRadioButton>
#include <memory>
class ImageBuilder
{
public:
    ImageBuilder();

    ~ImageBuilder();


    void BuildPng(QString name, QString dest = "");

    void BuildJpg(QString name, QString dest = "");

    void BuildTIF(QString name, QString dest = "");

    void Message(QString info);

private:
    QString directory;
    QFileInfo* info;
    void SetDirectory(QString name, QString dest);

};

#endif // IMAGEBUILDER_H
