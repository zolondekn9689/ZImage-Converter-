#ifndef ABSTRACTIMAGE_H
#define ABSTRACTIMAGE_H
#include <QString>
#include <QMessageBox>
#include <QPixmap>
#include <QPixelFormat>
#include <QDirIterator>
#include <QImageReader>
#include <QImage>


class AbstractImage
{
public:
    AbstractImage(QString fileExt, QString folderName);

    void BuildMessage(QString message);

    void Build(QString absoluteFileName);

    //virtual void Build(QString absoluteFileName, QImage::Format format);

    QString GetFolderName();

    QString GetFileExtension();

    QString GetDotFileExtension();

    QString GetSlashFolderName();

    QString BuildSavedPath(QString dir, QString filename);

private:
    ///
    /// \brief fileExtension
    ///
    QString fileExtension;
    QString dotFileExtension;

    QString folderName;
    QString slashFolderName;



};

#endif // ABSTRACTIMAGE_H
