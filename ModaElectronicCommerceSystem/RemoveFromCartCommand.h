#pragma once
#include "Command.h"
#include "Client.h"
#include "MyString.h"
class System;

class RemoveFromCartCommand : public Command
{
	Client& client;
	MyString& itemName;
	unsigned quantity;

public:
	RemoveFromCartCommand(Client& client, MyString& itemName, unsigned quantity); 
	void execute(System& system) override;
};

