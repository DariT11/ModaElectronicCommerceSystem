#pragma once
#include "Command.h"
#include "User.h"

class ViewProfileCommand :public Command
{
	User* user;

public:
	ViewProfileCommand(User* user);
	void execute() override;
};

