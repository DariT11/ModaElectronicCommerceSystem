#pragma once
#include "Command.h"
#include "MyString.h"
class System;

class ListOrdersCommand : public Command
{
public:
	ListOrdersCommand() = default;
	void execute(System& system) override;
};

