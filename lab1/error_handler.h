#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

enum errors
{
    NONE,
    FILE_NOT_FOUND,
    FILE_FORMAT_ERR,
    FILE_CONTENT_ERR,
    PTR_ALL_ERR,
    NO_DOTS,
    NO_LINKS,
    UNKNOWN_COMMAND
};

void error_message(errors err);

#endif // ERROR_HANDLER_H
