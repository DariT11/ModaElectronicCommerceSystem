#pragma once
#include "Command.h"
#include "User.h"
class System;

class ViewProfileCommand :public Command
{
	User* user;

public:
	ViewProfileCommand(User* user);
	void execute(System& system) override;
};

