#pragma once
#include "Command.h"
#include "User.h"
#include "System.h"

class LogOutCommand: public Command
{
	//User* user;

public:
	//LogOutCommand(User* user);
	void execute(System& system) override;
};

