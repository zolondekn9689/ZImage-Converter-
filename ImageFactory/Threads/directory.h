#ifndef DIRECTORY_H
#define DIRECTORY_H
#include <QString>
#include <QDirIterator>
#include <QThread>
class Directory : public QThread
{
public:
    Directory(QString dir);
    virtual void run();

    ~Directory();

    QString directory;
    QStringList* supportedFileList;
};

#endif // DIRECTORY_H
