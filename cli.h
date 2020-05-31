#pragma once

#include "session.h"
#include <string>
#include <vector>

class CommandLineInterface
{
public:
    CommandLineInterface();
    void setCommand(std::string _command);
    void executeCommand(std::vector<UserSession>& sessions);
    ~CommandLineInterface();

private:
    std::string command, lastCommand;
    size_t currSession;
    void load(std::vector<UserSession>& sessions);
    void close(std::vector<UserSession>& sessions);
    void save(std::vector<UserSession>& sessions);
    void saveas(std::vector<UserSession>& sessions);
    void help();
    void exit();

    void grayscale(std::vector<UserSession>& sessions);
    void monochrome(std::vector<UserSession>& sessions);
    void negative(std::vector<UserSession>& sessions);
    void rotate(std::vector<UserSession>& sessions);
    void undo(std::vector<UserSession>& sessions);
    void add(std::vector<UserSession>& sessions);
};