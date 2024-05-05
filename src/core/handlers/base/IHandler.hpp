#pragma once

class IHandler {
public:
    virtual void printMessage() = 0;
    virtual void handleAction() = 0;
};
