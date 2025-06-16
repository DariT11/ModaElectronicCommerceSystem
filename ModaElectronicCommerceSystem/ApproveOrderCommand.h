#pragma once
#include "Command.h"
#include "MyString.h"
class System;

class ApproveOrderCommand: public Command
{
	size_t index;
public:
	ApproveOrderCommand(size_t index);
	void execute(System& system) override;
};

