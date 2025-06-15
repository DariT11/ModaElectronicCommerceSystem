#pragma once
#include "Command.h"
#include "ItemsCatalog.h"

class FilterAlphabeticallyCommand :public Command
{
	ItemsCatalog& catalog;

public:
	FilterAlphabeticallyCommand(ItemsCatalog& catalog);
	void execute() override;
};

