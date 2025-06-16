#pragma once
#include "Command.h"
#include "MyString.h"
class System;

class ListBestSellingCommand: public Command
{
public:
	ListBestSellingCommand() = default;
	void execute(System& system) override;
};

