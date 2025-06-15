#pragma once
#include "Command.h"
#include "ItemsCatalog.h"
class System;

class FilterByRatingCommand:public Command
{
	ItemsCatalog& catalog;

public:
	FilterByRatingCommand(ItemsCatalog& catalog);
	void execute(System& system) override;
};

