#pragma once
#include "Command.h"
#include "Client.h"
#include "MyString.h"
#include "FinanceManager.h"

class RedeemCommand: public Command
{
	FinanceManager& fManager;
	Client& client;
	MyString code;

public:
	RedeemCommand(FinanceManager& fManager, Client& client, const MyString code);
	void execute() override;
};

