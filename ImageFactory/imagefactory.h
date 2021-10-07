#ifndef IMAGEFACTORY_H
#define IMAGEFACTORY_H
#include <QString>
#include <QDir>
#include "jpgimage.h"
#include "tifimage.h"
#include "pngimage.h"

class ImageFactory
{
public:


    static void BuildJpgDirectory(QString absoluteFilePath);
    static void BuildTifDirectory(QString absoluteFilePath);
    static void BuildPngDirectory(QString absoluteFilePath);

    static void BuildJpgImage(QString absoluteFilename);
    static void BuildTifImage(QString absoluteFilename);
    static void BuildPngImage(QString absoluteFilename);

private:
    ImageFactory();

};

#endif // IMAGEFACTORY_H
