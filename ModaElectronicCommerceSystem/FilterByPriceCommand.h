#pragma once
#include "ItemsCatalog.h"
#include "Command.h"

class FilterByPriceCommand: public Command
{
	ItemsCatalog& catalog;

public:
	FilterByPriceCommand(ItemsCatalog& catalog);
	void execute() override;
};

