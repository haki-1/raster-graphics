#pragma once

#include "netpbm.h"
#include <vector>
#include <string>

class UserSession
{
public:
    UserSession(std::vector<Netpbm*> _files);
    static size_t getPrevId();
    std::vector<Netpbm*>& getFiles();
    ~UserSession();

private:
    static size_t prevId;
    size_t id;
    std::vector<Netpbm*> files;
};