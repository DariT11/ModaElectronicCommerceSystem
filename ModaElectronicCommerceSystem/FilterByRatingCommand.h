#pragma once
#include "Command.h"
#include "ItemsCatalog.h"
class System;

class FilterByRatingCommand:public Command
{
public:
	FilterByRatingCommand();
	void execute(System& system) override;
};

