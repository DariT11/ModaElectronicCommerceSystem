#pragma once
#include "Command.h"
#include "MyString.h"
class System;

class RemoveItemCommand : public Command
{
	MyString name;

public:
	RemoveItemCommand(const MyString& name);
	void execute(System& system) override;
};

