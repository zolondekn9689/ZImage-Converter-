#ifndef TIFDIRECTORYBUILDER_H
#define TIFDIRECTORYBUILDER_H

#include <QThread>
#include <QDirIterator>
#include "ImageFactory/tifimage.h"

class TIFDirectoryBuilder : public QThread
{

public:
    TIFDirectoryBuilder(QString directory);

    void run();

private:
    QString Directory;
};

#endif // TIFDIRECTORYBUILDER_H
