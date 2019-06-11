#ifndef BUILDEREXCEPTION_H
#define BUILDEREXCEPTION_H

#include "baseException.h"

class NoBuildingObjectException : public BaseException
{
private:
    static constexpr const char* ErrorMsg = "Error existence building object";
public:
    explicit NoBuildingObjectException() : BaseException(ErrorMsg) {}
    explicit NoBuildingObjectException(const std::string& message) : \
        BaseException(ErrorMsg + message) {}
};

#endif // BUILDEREXCEPTION_H
