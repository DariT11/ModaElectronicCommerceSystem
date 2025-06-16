#pragma once
#include "Command.h"
#include "FinanceManager.h"
#include "Client.h"
class System;

class CheckBalanceCommand :public Command
{
public:
	CheckBalanceCommand();
	void execute(System& system) override;
};

