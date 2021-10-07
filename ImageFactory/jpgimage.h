#ifndef JPGIMAGE_H
#define JPGIMAGE_H
#include "abstractimage.h"

class JpgImage : public AbstractImage
{
public:
    JpgImage();




    // AbstractImage interface
public:
    void Build(QString filename);
};

#endif // JPGIMAGE_H
