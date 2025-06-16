#pragma once
#include "Command.h"
class System;

class ViewTransactionCommand: public Command
{
public:
	ViewTransactionCommand() = default;
	void execute(System& system) override;
};

