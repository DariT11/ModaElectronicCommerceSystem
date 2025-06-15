#pragma once
#include "ItemsCatalog.h"
#include "Command.h"
class System;

class FilterByPriceCommand: public Command
{
	ItemsCatalog& catalog;
	bool ascending;

public:
	FilterByPriceCommand(ItemsCatalog& catalog, bool ascending);
	void execute(System& system) override;
};

