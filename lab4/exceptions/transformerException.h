#ifndef TRANSFORMEXCEPTION_H
#define TRANSFORMEXCEPTION_H

#include "baseException.h"

class NoTransformingObjectException : public BaseException
{
private:
    static constexpr const char* ErrorMsg = "Error existence transforming object";
public:
    explicit NoTransformingObjectException() : BaseException(ErrorMsg) {}
    explicit NoTransformingObjectException(const std::string& message) : \
        BaseException(ErrorMsg + message) {}
};

class NoTransformingNodesException : public BaseException
{
private:
    static constexpr const char* ErrorMsg = "Error existence transforming nodes";
public:
    explicit NoTransformingNodesException() : BaseException(ErrorMsg) {}
    explicit NoTransformingNodesException(const std::string& message) : \
        BaseException(ErrorMsg + message) {}
};

#endif // TRANSFORMEXCEPTION_H
