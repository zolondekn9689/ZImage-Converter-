#ifndef TIFIMAGE_H
#define TIFIMAGE_H
#include "abstractimage.h"

class TifImage : public AbstractImage
{
public:
    TifImage();
    void Build(QString absoluteFileName);
};

#endif // TIFIMAGE_H
