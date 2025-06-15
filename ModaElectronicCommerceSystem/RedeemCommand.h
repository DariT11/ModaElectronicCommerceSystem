#pragma once
#include "Command.h"
#include "Client.h"
#include "Admin.h"
#include "MyString.h"
#include "FinanceManager.h"
class System;

class RedeemCommand: public Command
{
	FinanceManager& fManager;
	Client& client;
	Admin& admin;
	MyString code;

public:
	RedeemCommand(FinanceManager& fManager, Client& client, Admin& admin, const MyString code);
	void execute(System& system) override;
};

