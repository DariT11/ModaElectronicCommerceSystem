#pragma once
#include "Command.h"
#include "MyString.h"
class System;

class RejectOrderCommand: public Command
{
	MyString reason;
	size_t index;
public:
	RejectOrderCommand(size_t index, const MyString& reason);
	void execute(System& system) override;
};

