#pragma once
#include "Command.h"
#include "User.h"

class HelpCommand : public Command
{
	User* user;
public:
	HelpCommand(User* user);
	void execute() override;
};

