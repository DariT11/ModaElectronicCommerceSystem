#pragma once
#include "Command.h"
#include "MyString.h"
#include "Client.h"
class System;

class SendCheckCommand: public Command
{
public:
	SendCheckCommand() = default;
	void execute(System& system) override;
};

