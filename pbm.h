#pragma once
#include "netpbm.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class PortableBitMap : public Netpbm
{
public:
    PortableBitMap(std::string _fileName, char _magicNumber[2], size_t _width, size_t _height, std::vector<std::vector<bool>> _data);
    void save();
    Netpbm* clone();
    void grayscale();
    void monochrome();
    void negative();
    void rotate(std::string direction);
    void undo(std::string lastCommand);
    ~PortableBitMap();
    void print();


private:
    std::vector<std::vector<bool>> data;
    std::vector<std::vector<bool>> oldData;
};