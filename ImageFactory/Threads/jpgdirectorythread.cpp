#include "jpgdirectorythread.h"


JpgDirectoryThread::JpgDirectoryThread(QString directory) : QThread()
{
    this->directory = directory;
}


void JpgDirectoryThread::run()
{



    QDirIterator iter(this->directory, QStringList() << "*.jpg" << "*.tiff" << "*.tif" << "*.png", QDir::Files);
    //QDirIterator iter(Directory, list, QDir::Files);

    QString fileName;



    while(iter.hasNext())
    {
       iter.next();

       fileName = this->directory + "/" + iter.fileName();

        qDebug() << fileName;

       //Perform conversion.
       std::unique_ptr<JpgImage> image(new JpgImage());
       image->Build(fileName);
    }

}
