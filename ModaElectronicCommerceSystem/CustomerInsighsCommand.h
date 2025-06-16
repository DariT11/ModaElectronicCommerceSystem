#pragma once
#include "Client.h"
#include "Command.h"
#include "MyString.h"
class System;

class CustomerInsighsCommand: public Command
{
public:
	CustomerInsighsCommand() = default;
	void execute(System& system) override;
};

