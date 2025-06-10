#pragma once
#include "Command.h"
#include "Client.h"

class ViewCartCommand : public Command
{
	Client& client;

public:
	ViewCartCommand(Client& client);
	void execute() override;
};

