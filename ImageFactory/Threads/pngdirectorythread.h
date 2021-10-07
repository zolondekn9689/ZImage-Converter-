#ifndef PNGDIRECTORYTHREAD_H
#define PNGDIRECTORYTHREAD_H

#include <QThread>
#include <QDirIterator>
#include "ImageFactory/pngimage.h"


class PngDirectoryThread : public QThread
{

public:
    PngDirectoryThread(QString directory);

    void run();
private:
    QString Directory;
};

#endif // PNGDIRECTORYTHREAD_H
