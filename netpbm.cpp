#include "netpbm.h"

Netpbm::Netpbm(std::string _fileName, char _magicNumber[2], size_t _width, size_t _height) : 
fileName(_fileName), width(_width), height(_height)
{
    magicNumber[0] = _magicNumber[0];
    magicNumber[1] = _magicNumber[1];
}

Netpbm::~Netpbm()
{

}