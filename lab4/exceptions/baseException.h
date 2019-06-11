#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <exception>
#include <string>

class BaseException : public std::exception
{
public:
    BaseException();
    explicit BaseException(const char* message) : message(message) {}
    explicit BaseException(const std::string& message) : message(message) {}

    virtual const char* what() const noexcept override
    {
        return message.c_str();
    }

protected:
    std::string message;
};

#endif // BASEEXCEPTION_H
