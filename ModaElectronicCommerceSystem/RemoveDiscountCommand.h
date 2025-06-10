#pragma once
#include "Command.h"
#include "Client.h"

class RemoveDiscountCommand : public Command
{
	Client& client;

public:
	RemoveDiscountCommand(Client& client);
	void execute() override;
};

