#include "CommandFactory.h"
#include "LogOutCommand.h"
#include "ViewProfileCommand.h"
#include"CheckBalanceCommand.h"
#include "FinanceManager.h"
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
    else if (command == "view_profile")
    {
        return new ViewProfileCommand();
    }
    else if (command == "check_balance")
    {
       return new CheckBalanceCommand();
    }
    //else if(command == "")

    return nullptr;
}
