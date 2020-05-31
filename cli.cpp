#include "cli.h"
#include "netpbm.h"
#include "io.h"
#include <iostream>

CommandLineInterface::CommandLineInterface() : command(""), lastCommand(""), currSession(0) {}

void CommandLineInterface::setCommand(std::string _command)
{
    lastCommand = command;
    command = _command;
}

void CommandLineInterface::executeCommand(std::vector<UserSession>& sessions)
{
    if(command == "load" || command == "open") load(sessions);
    if(command == "close") close(sessions);
    if(command == "save") save(sessions);
    if(command == "saveas") saveas(sessions);
    if(command == "help") help();
    if(command == "exit") exit();
    if(command == "grayscale") grayscale(sessions);
    if(command == "monochrome") monochrome(sessions);
    if(command == "negative") negative(sessions);
    if(command == "rotate") rotate(sessions);
    if(command == "undo") undo(sessions);
    if(command == "add") add(sessions);
}

CommandLineInterface::~CommandLineInterface() {}

void CommandLineInterface::load(std::vector<UserSession>& sessions)
{
    sessions.push_back(UserSession({}));
    currSession = UserSession::getPrevId();
    std::cout << "Session with ID: " <<  currSession << " started" << std::endl;
    char c;
    do
    {
        add(sessions);
        std::cin.get(c);
    } while (c != '\n');

    // std::vector<Netpbm*> files;
    // std::string currFile;
    // char c;
    // do
    // {
    //     std::cin >> currFile;
    //     IOFile iofile{currFile};
    //     Netpbm *file = iofile.readFromFile();
    //     files.push_back(file);
    //     std::cin.get(c);
    // } while (c != '\n');
    // sessions.push_back(UserSession(files));
    // currSession = UserSession::getPrevId();
    // std::cout << "Session with ID: " <<  currSession << " started" << std::endl;

}

void CommandLineInterface::close(std::vector<UserSession>& sessions)
{
    sessions.erase(sessions.begin() + currSession - 1);
    currSession = 0;
    std::cout << "Successfully closed session with ID: " <<  currSession << std::endl;
}

void CommandLineInterface::save(std::vector<UserSession>& sessions)
{
    for (Netpbm *file : sessions[currSession - 1].getFiles())
    {
        file->save();
    }
}

void CommandLineInterface::saveas(std::vector<UserSession>& sessions)
{

}

void CommandLineInterface::help()
{

}

void CommandLineInterface::exit()
{

}

void CommandLineInterface::grayscale(std::vector<UserSession>& sessions)
{
    for (Netpbm *file : sessions[currSession - 1].getFiles())
    {
        file->grayscale();
    }
}

void CommandLineInterface::monochrome(std::vector<UserSession>& sessions)
{
    for (Netpbm *file : sessions[currSession - 1].getFiles())
    {
        file->monochrome();
    }
}

void CommandLineInterface::negative(std::vector<UserSession>& sessions)
{
    for (Netpbm *file : sessions[currSession - 1].getFiles())
    {
        file->negative();
    }
}

void CommandLineInterface::rotate(std::vector<UserSession>& sessions)
{
    std::string direction;
    std::cin >> direction;
    if(direction == "left" || direction == "right")
    {
        for (Netpbm *file : sessions[currSession - 1].getFiles())
        {
            file->rotate(direction);
        }
    }
}

void CommandLineInterface::undo(std::vector<UserSession>& sessions)
{
    for (Netpbm *file : sessions[currSession - 1].getFiles())
    {
        file->undo(lastCommand);
    }
}

void CommandLineInterface::add(std::vector<UserSession>& sessions)
{
    std::string currFile;
    std::cin >> currFile;
    IOFile iofile{currFile};
    Netpbm *file = iofile.readFromFile();
    sessions[currSession - 1].getFiles().push_back(file);
    std::cout << "Image \"" << currFile <<"\" added" << std::endl;
}
