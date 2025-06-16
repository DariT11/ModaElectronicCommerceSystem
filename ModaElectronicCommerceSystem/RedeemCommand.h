#pragma once
#include "Command.h"
#include "Client.h"
#include "Admin.h"
#include "MyString.h"
#include "FinanceManager.h"
class System;

class RedeemCommand: public Command
{
public:
	RedeemCommand();
	void execute(System& system) override;
};

