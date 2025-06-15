#pragma once
#include "Command.h"
#include "MyString.h"
#include "User.h"

class CommandFactory
{
	public:
		static Command* createCommand(const MyString& command, User* user);
};

