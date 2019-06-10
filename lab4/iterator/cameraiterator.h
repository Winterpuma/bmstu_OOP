#ifndef CAMERA_ITERATOR_H
#define CAMERA_ITERATOR_H

#include "baseobjectiterator.h"
#include "camera.h"

class Scene;

class CameraIterator : public BaseObjectIterator
{
private:
    Scene *scene;
public:
    CameraIterator();
    CameraIterator(Scene *_ch);

    CameraIterator &operator ++();
    ObjectPosition &operator *();
    ObjectPosition *operator ->();
    bool operator !=(CameraIterator &iter);
};

#endif // CAMERA_ITERATOR_H
