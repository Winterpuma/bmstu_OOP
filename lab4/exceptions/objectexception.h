#ifndef OBJECTEXCEPTION_H
#define OBJECTEXCEPTION_H

#include "baseException.h"

class OutOfRangeObjectException : public BaseException
{
private:
    static constexpr const char* ErrorMsg = "Error out of range of objects";
public:
    explicit OutOfRangeObjectException() : BaseException(ErrorMsg) {}
    explicit OutOfRangeObjectException(const std::string& message) : \
        BaseException(ErrorMsg + message) {}
};

#endif // OBJECTEXCEPTION_H

