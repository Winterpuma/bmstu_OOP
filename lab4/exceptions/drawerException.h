#ifndef DRAWEREXCEPTION_H
#define DRAWEREXCEPTION_H

#include "baseException.h"

class NoDrawingObjectException : public BaseException
{
private:
    static constexpr const char* ErrorMsg = "Error existence drawing object";
public:
    explicit NoDrawingObjectException() : BaseException(ErrorMsg) {}
    explicit NoDrawingObjectException(const std::string& message) : \
        BaseException(ErrorMsg + message) {}
};

class NoDrawingNodesException : public BaseException
{
private:
    static constexpr const char* ErrorMsg = "Error existence drawing nodes";
public:
    explicit NoDrawingNodesException() : BaseException(ErrorMsg) {}
    explicit NoDrawingNodesException(const std::string& message) : \
        BaseException(ErrorMsg + message) {}
};

class NoDrawingEdgesException : public BaseException
{
private:
    static constexpr const char* ErrorMsg = "Error existence drawing edges";
public:
    explicit NoDrawingEdgesException() : BaseException(ErrorMsg) {}
    explicit NoDrawingEdgesException(const std::string& message) : \
        BaseException(ErrorMsg + message) {}
};

#endif // DRAWEREXCEPTION_H
