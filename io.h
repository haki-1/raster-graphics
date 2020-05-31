#pragma once
#include "pbm.h"
#include "pgm.h"
#include "ppm.h"
#include <fstream>
#include <string>
#include <iostream>

class IOFile
{
public:
    IOFile(std::string _fileName);
    void setFileName(std::string _fileName);
    Netpbm* readFromFile();
    //void WriteToFile();

private:
    std::string fileName;
    PortableBitMap* readPBM();
    PortableGrayMap* readPGM();
    PortablePixMap* readPPM();
};