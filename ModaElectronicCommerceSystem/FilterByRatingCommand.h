#pragma once
#include "Command.h"
#include "ItemsCatalog.h"

class FilterByRatingCommand:public Command
{
	ItemsCatalog& catalog;

public:
	FilterByRatingCommand(ItemsCatalog& catalog);
	void execute() override;
};

