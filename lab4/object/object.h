#ifndef OBJECT_H
#define OBJECT_H

class Object
{
public:
    Object() = default;
    virtual ~Object() = default;

    virtual bool isVisible() = 0;
};

class VisibleObject : public Object
{
public:
    VisibleObject() = default;

    bool isVisible() override
    {
        return true;
    }
};

class InvisibleObject : public Object
{
public:
    InvisibleObject() = default;

    bool isVisible() override
    {
        return false;
    }
};

#endif // OBJECT_H
