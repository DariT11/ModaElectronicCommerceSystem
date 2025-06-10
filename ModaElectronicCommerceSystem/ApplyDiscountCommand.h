#pragma once
#include "Command.h"
#include "Client.h"

class ApplyDiscountCommand :public Command
{
	Client& client;

public:
	ApplyDiscountCommand(Client& cliet);
	void execute() override;
};

