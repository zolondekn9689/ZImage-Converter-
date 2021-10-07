#include "directory.h"

Directory::Directory(QString dir)
{
    this->directory = dir;
    supportedFileList = new QStringList();
    supportedFileList->append("*.jpg");
    supportedFileList->append("*.tiff");
    supportedFileList->append("*.png");

}


Directory::~Directory()
{
    delete supportedFileList;
}
