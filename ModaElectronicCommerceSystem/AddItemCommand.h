#pragma once
#include "Command.h"
#include "MyString.h"
class System;

class AddItemCommand: public Command
{
	MyString name, description;
	double price;
	unsigned quantity;

public:
	AddItemCommand(const MyString& name, double price, unsigned quantity, const MyString& description);
	void execute(System& system) override;
};

