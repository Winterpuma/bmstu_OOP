#ifndef COMPOSITEOBJECT_H
#define COMPOSITEOBJECT_H

#include "model.h"
#include "camera.h"
#include "iterator/iterator.h"
#include "exceptions/objectexception.h"

#include <vector>

class CompositeObject : public Object
{
public:
    CompositeObject();

    void addModel(std::shared_ptr<Object> object);
    void removeModel(const size_t index);

    void addCamera(std::shared_ptr<Object> object);
    void removeCamera(const size_t index);

    std::shared_ptr<Object> getModel(const size_t index);
    std::shared_ptr<Object> getCamera(const size_t index);

    ObjIter objectBegin();
    ObjIter objectEnd();
    ObjIter modelIndex(const size_t index);
    ObjIter cameraIndex(const size_t index);

    bool isVisible() override {return true;}

private:
    std::vector<std::shared_ptr<Object>> objects;
    size_t countModel;
    size_t countCamera;
};

#endif // COMPOSITEOBJECT_H
