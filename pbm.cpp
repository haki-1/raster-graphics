#include "pbm.h"

PortableBitMap::PortableBitMap(std::string _fileName, char _magicNumber[2], size_t _width, size_t _height, std::vector<std::vector<bool>> _data) : 
Netpbm(_fileName, _magicNumber, _width, _height), data(_data), oldData(_data) {}

void PortableBitMap::save()
{
    std::ofstream file(fileName);
    if(file)
    {
        file << magicNumber[0] << magicNumber[1] << std::endl << width << " " << height << std::endl;
        for (size_t i = 0; i < height; ++i)
        {
            for (size_t j = 0; j < width; ++j)
            {
                file << data[i][j] << " ";
            }
            file << std::endl;
        }
    }
}

Netpbm* PortableBitMap::clone()
{
    return nullptr;
}

void PortableBitMap::grayscale() {}

void PortableBitMap::monochrome() {}

void PortableBitMap::negative()
{
    oldData = data;
    for (size_t i = 0; i < height; ++i)
    {
        for (size_t j = 0; j < width; ++j)
        {
            data[i][j] = !data[i][j];
        }
    }
}

void PortableBitMap::rotate(std::string direction)
{
    oldData = data;
    std::vector<std::vector<bool>> newData;
    if(direction == "left")
    {
        for (size_t i = width; i > 0; --i)
        {
            std::vector<bool> newRow;
            for (size_t j = 0; j < height; ++j)
            {
                newRow.push_back(data[j][i - 1]);
            }
            newData.push_back(newRow);
        }
    }
    else
    {
        for (size_t i = 0; i < width; ++i)
        {
            std::vector<bool> newRow;
            for (size_t j = height; j > 0; --j)
            {
                newRow.push_back(data[j - 1][i]);
            }
            newData.push_back(newRow);
        }
    }
    data = newData;
    std::swap(width, height);

}

void PortableBitMap::print()
{
    for (std::vector<bool> v : data)
    {
        for (bool b : v)
        {
            std::cout << b;
        }
        std::cout << std::endl;
    }
}

void PortableBitMap::undo(std::string lastCommand)
{
    if(lastCommand == "rotate") std::swap(width, height);
    data = oldData;
}

PortableBitMap::~PortableBitMap()
{

}