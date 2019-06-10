#include "cameraiterator.h"
#include "scene.h"
#include <iostream>

CameraIterator::CameraIterator()
{
    this->scene = nullptr;
    this->current_child = std::shared_ptr<ObjectPosition>(nullptr);
}

CameraIterator::CameraIterator(Scene *_ch)
{
    this->scene = _ch;
    if (this->scene->cameras.size() > 0)
        this->current_child = this->scene->cameras[0];
    else
        this->current_child = std::shared_ptr<ObjectPosition>(nullptr);
}


ObjectPosition &CameraIterator::operator *()
{
    return *(this->current_child.lock().get());
}

ObjectPosition *CameraIterator::operator ->()
{
    return this->current_child.lock().get();
}

CameraIterator &CameraIterator::operator ++()
{
    this->child_id++;
    if (this->child_id >= this->scene->cameras.size())
        this->current_child = std::shared_ptr<ObjectPosition>(nullptr);
    else
        this->current_child = this->scene->cameras[this->child_id];
    return *this;
}

bool CameraIterator::operator !=(CameraIterator &iter)
{
    return this->child_id != iter.child_id;
}
