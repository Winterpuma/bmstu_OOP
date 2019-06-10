#include "objectiterator.h"

#include "scene.h"

ObjectIterator::ObjectIterator(Composite *_parent) : BaseObjectIterator(_parent)
{

}

ObjectIterator::ObjectIterator()
{

}


ObjectIterator &ObjectIterator::operator ++()
{
    this->child_id++;
    if (this->child_id >= this->parent->children.size())
        this->current_child = std::shared_ptr<ObjectPosition>(nullptr);
    else
        this->current_child = this->parent->children[this->child_id];
    return *this;
}

ObjectPosition &ObjectIterator::operator *()
{
    return *(this->current_child.lock());
}

ObjectPosition *ObjectIterator::operator ->()
{
    return this->current_child.lock().get();
}

bool ObjectIterator::operator !=(ObjectIterator &iter)
{
    return this->child_id != iter.child_id;
}
