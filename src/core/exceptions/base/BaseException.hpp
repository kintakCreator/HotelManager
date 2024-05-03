#include <string>

struct BaseException {
    BaseException(int errorCode): errorCode(errorCode) { }

    int errorCode;
    virtual std::string what() = 0;
};
