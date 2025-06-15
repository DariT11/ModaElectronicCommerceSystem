#pragma once
#include "Command.h"
#include "Client.h"
#include "ItemsCatalog.h"
class System;

class AddToCartCommand: public Command
{
	Client& client;
	ItemsCatalog& catalog;
	unsigned itemId;
	unsigned quantity;

public:
	AddToCartCommand(Client& client, ItemsCatalog& catalog, unsigned itemId, unsigned quantity);
	void execute(System& system) override;
};

