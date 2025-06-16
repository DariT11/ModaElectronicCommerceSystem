#pragma once
#include "Command.h"

class ViewProductCommand : public Command
{
	unsigned id;
public:
	ViewProductCommand(unsigned id);
	void execute(System& system) override;
};

