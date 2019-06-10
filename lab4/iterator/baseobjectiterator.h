#ifndef BASEOBJECTITERATOR_H
#define BASEOBJECTITERATOR_H

#include <memory>

class ObjectPosition;
class Composite;

class BaseObjectIterator
{
protected:
    Composite *parent;
    std::weak_ptr<ObjectPosition> current_child;
    size_t child_id = 0;
public:
    BaseObjectIterator() {}
    BaseObjectIterator(Composite *_parent);
};

#endif // BASEOBJECTITERATOR_H
