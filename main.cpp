#include "cli.h"
#include "session.h"
#include <iostream>


int main()
{
    CommandLineInterface cli;
    std::vector<UserSession> sessions;
    std::string command;
    while (true)
    {
        std::cin >> command;
        cli.setCommand(command);
        cli.executeCommand(sessions);
    }


    // in class destr there must be delete on in-vector pointers,
    // but since we are in main, does i really need vector of us*
    // it might be better to be from objects!!!!!!!!!!

    // virt destr ? - yep

    // copy actually means that we create copy of pointers, so
    // memory becomes shared!!!

    // that's why we need copy-constructor to properly copy the
    // vector!!!
    
    return 0;
}