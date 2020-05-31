#pragma once
#include <string>
#include <vector>

class Netpbm
{
public:
    Netpbm(std::string _fileName, char _magicNumber[2], size_t _width, size_t _height);
    virtual void save() = 0;
    virtual Netpbm* clone() = 0;
    virtual void grayscale() = 0;
    virtual void monochrome() = 0;
    virtual void negative() = 0;
    virtual void rotate(std::string direction) = 0;
    virtual void undo(std::string lastCommand) = 0;
    virtual ~Netpbm();

protected:
    std::string fileName;
    char magicNumber[2];
    size_t width, height;
};