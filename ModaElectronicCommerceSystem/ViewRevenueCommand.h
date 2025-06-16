#pragma once
#include "Command.h"
#include "MyString.h"
class System;

class ViewRevenueCommand:public Command
{
public:
	ViewRevenueCommand() = default;
	void execute(System& system) override;
};

