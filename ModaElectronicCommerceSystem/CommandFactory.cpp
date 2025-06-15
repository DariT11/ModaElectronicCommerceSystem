#include "CommandFactory.h"
#include "LogOutCommand.h"
#include "HelpCommand.h"

CommandFactory& CommandFactory::getInstance()
{
    static CommandFactory commandFactory;
    return commandFactory;
}

Command* CommandFactory::createCommand(const MyString& command)
{
    if (command == "logout")
    {
        return new LogOutCommand();
    }
    else if (command == "help") 
    {
        return new HelpCommand();
    }

    return nullptr;
}
