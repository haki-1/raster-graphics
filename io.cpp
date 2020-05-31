#include "io.h"

IOFile::IOFile(std::string _fileName) : fileName(_fileName){}

void IOFile::setFileName(std::string _fileName)
{
    fileName = _fileName;
}

Netpbm* IOFile::readFromFile()
{
    std::string extension = fileName.substr(fileName.find(".") + 1);
    if(extension == "ppm") return readPPM();
    if(extension == "pgm") return readPGM();
    if(extension == "pbm") return readPBM();
    return nullptr;
}

// void IOFile::WriteToFile()
// {
    
// }


PortableBitMap* IOFile::readPBM()
{
    std::ifstream file(fileName);
    if(file)
    {
        char magicNumber[2];
        size_t width, height;
        file.get(magicNumber[0]);
        file.get(magicNumber[1]);
        file >> std::ws >> width >> std::ws >> height;
        std::vector<std::vector<bool>> data;
        for (size_t i = 0; i < height; ++i)
        {
            std::vector<bool> row;
            for (size_t j = 0; j < width; ++j)
            {
                file >> std::ws;
                char c;
                file.get(c);
                if(c == '1') row.push_back(true);
                if(c == '0') row.push_back(false);
            }
            data.push_back(row);
        }
        PortableBitMap* pbm = new PortableBitMap(fileName, magicNumber, width, height, data);
        pbm->print();
        file.close();
        return pbm;
    }
    file.close();
    std::cout << "not found" << std::endl;
    return nullptr;
}

PortableGrayMap* IOFile::readPGM()
{
    std::ifstream file(fileName);
    if(file)
    {
        char magicNumber[2];
        size_t maxValueWhite, width, height;
        file.get(magicNumber[0]);
        file.get(magicNumber[1]);
        file >> std::ws >> width >> std::ws >> height >> std::ws >> maxValueWhite;
        std::vector<std::vector<size_t>> data;
        for (size_t i = 0; i < height; ++i)
        {
            std::vector<size_t> row;
            for (size_t j = 0; j < width; ++j)
            {
                file >> std::ws;
                size_t c;
                file >> c;
                row.push_back(c);
            }
            data.push_back(row);
        }
        PortableGrayMap* pgm = new PortableGrayMap(fileName, magicNumber, width, height, maxValueWhite, data);
        pgm->print();
        file.close();
        return pgm;
    }
    file.close();
    std::cout << "not found" << std::endl;
    return nullptr;
}

PortablePixMap* IOFile::readPPM()
{
    std::ifstream file(fileName);
    if(file)
    {
        char magicNumber[2];
        size_t maxValueColour, width, height;
        file.get(magicNumber[0]);
        file.get(magicNumber[1]);
        file >> std::ws >> width >> std::ws >> height >> std::ws >> maxValueColour;
        std::vector<std::vector<PortablePixMap::RGB>> data;
        for (size_t i = 0; i < height; ++i)
        {
            std::vector<PortablePixMap::RGB> row;
            for (size_t j = 0; j < width; ++j)
            {
                file >> std::ws;
                size_t r, g, b;
                file >> std::ws >> r >> std::ws >> g >> std::ws >> b;
                row.push_back({r,g,b});
            }
            data.push_back(row);
        }
        PortablePixMap* ppm = new PortablePixMap(fileName, magicNumber, width, height, maxValueColour, data);
        ppm->print();
        file.close();
        return ppm;
    }
    file.close();
    std::cout << "not found" << std::endl;
    return nullptr;
}