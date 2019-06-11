#include "compositeobject.h"

CompositeObject::CompositeObject() : countModel(0), countCamera(0) {}

void CompositeObject::addModel(std::shared_ptr<Object> object)
{
    objects.push_back(std::static_pointer_cast<Model>(object));
    ++countModel;
}

void CompositeObject::removeModel(const size_t index)
{
    size_t count = 0;
    size_t i = 0;

    for (; i < objects.size(); ++i)
    {
        if (objects[i]->isVisible())
            ++count;
        if (count == index + 1)
            break;
    }

    if (count != index + 1)
    {
        throw OutOfRangeObjectException(": removeModel");
    }
    else
    {
        objects.erase(objects.begin() + i);
        --countModel;
    }
}

void CompositeObject::addCamera(std::shared_ptr<Object> object)
{
    objects.push_back(std::static_pointer_cast<Camera>(object));
    ++countCamera;
}

void CompositeObject::removeCamera(const size_t index)
{
    size_t count = 0;
    size_t i = 0;

    for (; i < objects.size(); ++i)
    {
        if (!objects[i]->isVisible())
            ++count;
        if (count == index + 1)
            break;
    }

    if (count != index + 1)
    {
        throw OutOfRangeObjectException(": removeCamera");
    }
    else
    {
        objects.erase(objects.begin() + i);
        --countModel;
    }
}

std::shared_ptr<Object> CompositeObject::getModel(const size_t index)
{
    size_t count = 0;
    size_t i = 0;

    for (; i < objects.size(); ++i)
    {
        if (objects[i]->isVisible())
            ++count;
        if (count == index + 1)
            break;
    }

    if (count != index + 1)
        throw OutOfRangeObjectException(": getModel");
    else
        return objects[i];
}

std::shared_ptr<Object> CompositeObject::getCamera(const size_t index)
{
    size_t count = 0;
    size_t i = 0;

    for (; i < objects.size(); ++i)
    {
        if (!objects[i]->isVisible())
            ++count;
        if (count == index + 1)
            break;
    }

    if (count != index + 1)
        throw OutOfRangeObjectException(": getCamera");
    else
        return objects[i];
}

ObjIter CompositeObject::objectBegin()
{
    return objects.begin();
}

ObjIter CompositeObject::objectEnd()
{
    return objects.end();
}

ObjIter CompositeObject::modelIndex(const size_t index)
{
    if (index == countModel)
        return objects.end();

    size_t count = 0;
    size_t i = 0;

    for (; i < objects.size(); ++i)
    {
        if (objects[i]->isVisible())
            ++count;
        if (count == index + 1)
            break;
    }

    if (count != index + 1)
        throw OutOfRangeObjectException(": modelIndex");
    else
        return objects.begin() + i;
}

ObjIter CompositeObject::cameraIndex(const size_t index)
{
    if (index == countCamera)
        return objects.end();

    size_t count = 0;
    size_t i = 0;

    for (; i < objects.size(); ++i)
    {
        if (!objects[i]->isVisible())
            ++count;
        if (count == index + 1)
            break;
    }

    if (count != index + 1)
        throw OutOfRangeObjectException(": cameraIndex");
    else
        return objects.begin() + i;
}

