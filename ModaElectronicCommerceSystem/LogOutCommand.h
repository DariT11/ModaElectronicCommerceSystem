#pragma once
#include "Command.h"
#include "User.h"
#include "System.h"

class LogOutCommand: public Command
{
public:
	void execute(System& system) override;
};

