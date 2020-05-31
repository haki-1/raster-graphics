#pragma once
#include "netpbm.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class PortableGrayMap : public Netpbm
{
public:
    PortableGrayMap(std::string _fileName, char _magicNumber[2], size_t _width, size_t _height, size_t maxValueWhite, std::vector<std::vector<size_t>> data);
    void save();
    Netpbm* clone();
    void grayscale();
    void monochrome();
    void negative();
    void rotate(std::string direction);
    void undo(std::string lastCommand);
    ~PortableGrayMap();
    void print();


private:
    size_t maxValueWhite;
    std::vector<std::vector<size_t>> data;
    std::vector<std::vector<size_t>> oldData;
};