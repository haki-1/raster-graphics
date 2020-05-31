#include "pgm.h"

PortableGrayMap::PortableGrayMap(std::string _fileName, char _magicNumber[2], size_t _width, size_t _height, size_t _maxValueWhite, std::vector<std::vector<size_t>> _data) : 
Netpbm(_fileName, _magicNumber, _width, _height), maxValueWhite(_maxValueWhite), data(_data), oldData(_data) {}

void PortableGrayMap::save()
{
    std::ofstream file(fileName);
    if(file)
    {
        file << magicNumber[0] << magicNumber[1] << std::endl << width << " " << height << std::endl << maxValueWhite << std::endl;
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

Netpbm* PortableGrayMap::clone()
{
    return nullptr;
}

void PortableGrayMap::grayscale() {}

void PortableGrayMap::monochrome()
{
    oldData = data;
    for (size_t i = 0; i < height; ++i)
    {
        for (size_t j = 0; j < width; ++j)
        {
            if(data[i][j] > maxValueWhite / 2) data[i][j] = maxValueWhite;
            else data[i][j] = 0;
        }
    }
}

void PortableGrayMap::negative()
{
    oldData = data;
    for (size_t i = 0; i < height; ++i)
    {
        for (size_t j = 0; j < width; ++j)
        {
            data[i][j] = maxValueWhite - data[i][j];
        }
    }
}

void PortableGrayMap::rotate(std::string direction)
{
    oldData = data;
    std::vector<std::vector<size_t>> newData;
    if(direction == "left")
    {
        for (size_t i = width; i > 0; --i)
        {
            std::vector<size_t> newRow;
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
            std::vector<size_t> newRow;
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

void PortableGrayMap::undo(std::string lastCommand)
{
    if(lastCommand == "rotate") std::swap(width, height);
    data = oldData;
}

PortableGrayMap::~PortableGrayMap()
{

}

void PortableGrayMap::print()
{
    for (std::vector<size_t> v : data)
    {
        for (size_t b : v)
        {
            std::cout << b;
        }
        std::cout << std::endl;
    }
}