#include "baseobjectiterator.h"

#include "scene.h"

BaseObjectIterator::BaseObjectIterator(Composite *_parent)
{
    this->parent = _parent;
}
