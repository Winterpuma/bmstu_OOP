#ifndef UPLOADEREXCEPTION_H
#define UPLOADEREXCEPTION_H

#include "baseException.h"

class OpenFileException : public BaseException
{
private:
    static constexpr const char* ErrorMsg = "Error opening file";
public:
    explicit OpenFileException() : BaseException(ErrorMsg) {}
    explicit OpenFileException(const std::string& message) : \
        BaseException(ErrorMsg + message) {}
};

class CloseFileException : public BaseException
{
private:
    static constexpr const char* ErrorMsg = "Error closing file";
public:
    explicit CloseFileException() : BaseException(ErrorMsg) {}
    explicit CloseFileException(const std::string& message) : \
        BaseException(ErrorMsg + message) {}
};

class ReadFileException : public BaseException
{
private:
    static constexpr const char* ErrorMsg = "Error reading file";
public:
    explicit ReadFileException() : BaseException(ErrorMsg) {}
    explicit ReadFileException(const std::string& message) : \
        BaseException(ErrorMsg + message) {}
};

#endif // UPLOADEREXCEPTION_H

