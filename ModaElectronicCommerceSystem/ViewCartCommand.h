#pragma once
#include "Command.h"
#include "Client.h"
class System;

class ViewCartCommand : public Command
{
	Client& client;

public:
	ViewCartCommand(Client& client);
	void execute(System& system) override;
};

