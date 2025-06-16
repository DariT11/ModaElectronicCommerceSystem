#pragma once
#include "ItemsCatalog.h"
#include "Command.h"
class System;

class FilterByPriceCommand: public Command
{
	bool ascending;

public:
	FilterByPriceCommand(bool ascending);
	void execute(System& system) override;
};

