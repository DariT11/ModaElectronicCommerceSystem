#pragma once
#include "Command.h"
#include "Client.h"
#include "BusinessProfile.h"
class System;

class ChekoutCommand :public Command
{
	Client& client;
	BusinessProfile& businessP;

public:
	ChekoutCommand(Client& client, BusinessProfile& businessP);
	void execute(System& system) override;
};

