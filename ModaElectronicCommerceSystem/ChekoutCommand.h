#pragma once
#include "Command.h"
#include "Client.h"
#include "BusinessProfile.h"

class ChekoutCommand :public Command
{
	Client& client;
	BusinessProfile& businessP;

public:
	ChekoutCommand(Client& client, BusinessProfile& businessP);
	void execute() override;
};

