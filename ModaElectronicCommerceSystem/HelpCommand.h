#pragma once
#include "Command.h"
#include "User.h"
class System;

class HelpCommand : public Command
{
public:
	void execute(System& system) override;
};

