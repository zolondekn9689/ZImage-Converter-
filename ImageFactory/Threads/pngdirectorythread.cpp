#include "pngdirectorythread.h"





PngDirectoryThread::PngDirectoryThread(QString directory) : QThread()
{
    Directory = directory;
}


void PngDirectoryThread::run()
{



    QDirIterator iter(this->Directory, QStringList() << "*.jpg" << "*.tiff" << "*.tif" << "*.png", QDir::Files);

    QString fileName;



    while(iter.hasNext())
    {
       iter.next();

       fileName = this->Directory + "/" + iter.fileName();


       PngImage im;
       im.Build(fileName);

    }

}
