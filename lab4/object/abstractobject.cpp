#include "abstractobject.h"

size_t AbstractObject::object_count = 0;

AbstractObject::AbstractObject() :
    id(AbstractObject::object_count)
{
    AbstractObject::object_count++;
}

AbstractObject::~AbstractObject()
{
    AbstractObject::object_count--;
}
