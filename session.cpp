#include "session.h"

#include <iostream>
size_t UserSession::prevId = 0;


UserSession::UserSession(std::vector<Netpbm*> _files) : id(++prevId), files(_files)
{

    // std::cout << "My els are:" << std::endl;
    // for (std::string s : files)
    // {
    //     std::cout << s << ", ";
    // }
}

size_t UserSession::getPrevId()
{
    return prevId;
}

std::vector<Netpbm*>& UserSession::getFiles()
{
    return files;
}

UserSession::~UserSession()
{
    std::cout <<"dest of US"; 
}