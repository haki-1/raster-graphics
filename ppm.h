#pragma once
#include "netpbm.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class PortablePixMap : public Netpbm
{
public:
    struct RGB
    {
        size_t red, green, blue;
    };
    
    PortablePixMap(std::string _fileName, char _magicNumber[2], size_t _width, size_t _height, size_t _maxValueColour, std::vector<std::vector<RGB>> _data);
    void save();
    Netpbm* clone();
    void grayscale();
    void monochrome();
    void negative();
    void rotate(std::string direction);
    void undo(std::string lastCommand);
    ~PortablePixMap();
    void print();


private:

    size_t maxValueColour;
    std::vector<std::vector<RGB>> data;
    std::vector<std::vector<RGB>> oldData;
};