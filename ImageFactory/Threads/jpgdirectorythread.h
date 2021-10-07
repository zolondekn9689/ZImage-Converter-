#ifndef JPGDIRECTORYTHREAD_H
#define JPGDIRECTORYTHREAD_H

#include <QThread>
#include <QDirIterator>
#include <QString>
#include <QDir>
#include <QStringList>
#include "ImageFactory/jpgimage.h"


class JpgDirectoryThread : public QThread
{

public:
    JpgDirectoryThread(QString directory);

    void run();
private:
    QString directory;
};

#endif // JPGDIRECTORYTHREAD_H
