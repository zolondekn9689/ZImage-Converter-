#include "tifdirectorybuilder.h"

TIFDirectoryBuilder::TIFDirectoryBuilder(QString directory) : QThread()
{
    this->Directory = directory;
}

void TIFDirectoryBuilder::run()
{

    QDirIterator iter(this->Directory, QStringList() << "*.jpg" << "*.tiff" << "*.tif" << "*.png", QDir::Files);

    QString fileName;



    while(iter.hasNext())
    {
       iter.next();

       fileName = this->Directory + "/" + iter.fileName();


       TifImage im;
       im.Build(fileName);

    }


}
