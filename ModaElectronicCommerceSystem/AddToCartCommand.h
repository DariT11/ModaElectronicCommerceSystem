#pragma once
#include "Command.h"
#include "Client.h"
#include "ItemsCatalog.h"
class System;

class AddToCartCommand: public Command
{
	unsigned itemId;
	unsigned quantity;

public:
	AddToCartCommand(unsigned itemId, unsigned quantity);
	void execute(System& system) override;
};

