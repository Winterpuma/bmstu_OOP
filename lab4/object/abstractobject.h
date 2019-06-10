#ifndef ABSTRACT_OBJECT_H
#define ABSTRACT_OBJECT_H

#include <typeinfo.h>

class AbstractObject
{
protected:
    static size_t object_count;

    const size_t id;
public:
    AbstractObject();

    virtual size_t get_id() = 0;

    ~AbstractObject();
};

#endif // ABSTRACT_OBJECT_H
