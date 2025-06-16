#pragma once
#include "Command.h"
#include "MyString.h"
class System;

class ListRefundCommand: public Command
{
public:
	ListRefundCommand() = default;
	void execute(System& system) override;
};

