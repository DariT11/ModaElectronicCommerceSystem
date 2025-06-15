#pragma once
#include "Command.h"
#include "Client.h"
class System;

class ApplyDiscountCommand :public Command
{
	Client& client;

public:
	ApplyDiscountCommand(Client& cliet);
	void execute(System& system) override;
};

