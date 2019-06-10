#ifndef OBJECT_ITERATOR_H
#define OBJECT_ITERATOR_H

#include <iterator>
#include <memory>
#include <vector>

#include "baseobjectiterator.h"


class ObjectIterator : public BaseObjectIterator
{
public:
    ObjectIterator();
    ObjectIterator(Composite *_parent);

    ObjectPosition &operator *();
    ObjectPosition *operator ->();
    ObjectIterator &operator ++();
    bool operator !=(ObjectIterator &iter);
};

#endif // OBJECT_ITERATOR_H
