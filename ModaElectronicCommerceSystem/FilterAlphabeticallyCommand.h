#pragma once
#include "Command.h"
#include "ItemsCatalog.h"
class System;

class FilterAlphabeticallyCommand :public Command
{
public:
	FilterAlphabeticallyCommand();
	void execute(System& system) override;
};

