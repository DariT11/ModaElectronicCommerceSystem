#pragma once
#include "Command.h"
#include "MyString.h"
class System;

class RejectRefundCommand: public Command
{
	size_t index;
	MyString reason;

public:
	RejectRefundCommand(size_t index, const MyString& reason);
	void execute(System& system) override;
};

