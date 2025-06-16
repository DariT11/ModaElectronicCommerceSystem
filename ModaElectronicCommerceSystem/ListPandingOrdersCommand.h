#pragma once
#include "Command.h"
#include "MyString.h"
class System;

class ListPandingOrdersCommand: public Command
{
public:
	ListPandingOrdersCommand() = default;
	void execute(System& system) override;
};

