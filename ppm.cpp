#include "ppm.h"

PortablePixMap::PortablePixMap(std::string _fileName, char _magicNumber[2], size_t _width, size_t _height, size_t _maxValueColour, std::vector<std::vector<RGB>> _data) : 
Netpbm(_fileName, _magicNumber, _width, _height), maxValueColour(_maxValueColour), data(_data), oldData(_data) {}

void PortablePixMap::save()
{
    std::ofstream file(fileName);
    if(file)
    {
        file << magicNumber[0] << magicNumber[1] << std::endl << width << " " << height << std::endl << maxValueColour << std::endl;
        for (size_t i = 0; i < height; ++i)
        {
            for (size_t j = 0; j < width; ++j)
            {
                file << data[i][j].red << " " << data[i][j].green << " " << data[i][j].blue << " ";
            }
            file << std::endl;
        }
    }
}

Netpbm* PortablePixMap::clone()
{
    return nullptr;
}

void PortablePixMap::grayscale()
{
    oldData = data;
    for (size_t i = 0; i < height; ++i)
    {
        for (size_t j = 0; j < width; ++j)
        {
            size_t gsPixel = (data[i][j].red + data[i][j].green + data[i][j].blue) / 3;
            data[i][j].red = data[i][j].green = data[i][j].blue = gsPixel;
        }
    }
}

void PortablePixMap::monochrome()
{
    oldData = data;
    for (size_t i = 0; i < height; ++i)
    {
        for (size_t j = 0; j < width; ++j)
        {
            size_t gsPixel = (data[i][j].red + data[i][j].green + data[i][j].blue) / 3;
            if(gsPixel > maxValueColour / 2) data[i][j].red = data[i][j].green = data[i][j].blue = maxValueColour;
            else data[i][j].red = data[i][j].green = data[i][j].blue = 0;
        }
    }
}

void PortablePixMap::negative()
{
    oldData = data;
    for (size_t i = 0; i < height; ++i)
    {
        for (size_t j = 0; j < width; ++j)
        {
            data[i][j].red = maxValueColour - data[i][j].red;
            data[i][j].green = maxValueColour - data[i][j].green;
            data[i][j].blue = maxValueColour - data[i][j].blue;
        }
    }
}

void PortablePixMap::rotate(std::string direction)
{
    oldData = data;
    std::vector<std::vector<RGB>> newData;
    if(direction == "left")
    {
        for (size_t i = width; i > 0; --i)
        {
            std::vector<RGB> newRow;
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
            std::vector<RGB> newRow;
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

void PortablePixMap::undo(std::string lastCommand)
{
    if(lastCommand == "rotate") std::swap(width, height);
    data = oldData;
}

PortablePixMap::~PortablePixMap()
{

}

void PortablePixMap::print()
{
    for (std::vector<RGB> v : data)
    {
        for (RGB c : v)
        {
            std::cout << c.red << " " << c.green << " " << c.blue;
        }
        std::cout << std::endl;
    }
}