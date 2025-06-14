#pragma once
#include "Command.h"
#include "User.h"

class LogOutCommand: public Command
{
	User* user;

public:
	LogOutCommand(User* user);
	void execute() override;
};

