#pragma once
#include "Command.h"
#include "FinanceManager.h"
#include "Client.h"

class CheckBalanceCommand :public Command
{
	FinanceManager& fManager;
	Client& client;

public:
	CheckBalanceCommand(FinanceManager& fManager, Client& client);
	void execute() override;
};

