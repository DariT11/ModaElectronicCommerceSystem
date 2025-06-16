#pragma once
#include "Command.h"
#include "MyString.h"
class System;

class ApproveRefundCommand: public Command
{
	size_t index;
public:
	ApproveRefundCommand(size_t index);
	void execute(System& system) override;
};

