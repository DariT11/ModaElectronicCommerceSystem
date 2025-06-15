#pragma once
#include "Command.h"
#include "Client.h"
class System;

class RemoveDiscountCommand : public Command
{
	Client& client;

public:
	RemoveDiscountCommand(Client& client);
	void execute(System& system) override;
};

