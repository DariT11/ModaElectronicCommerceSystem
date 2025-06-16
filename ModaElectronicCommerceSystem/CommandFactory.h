#pragma once
#include "Command.h"
#include "MyString.h"
#include "User.h"
#include "System.h"

class CommandFactory
{
	CommandFactory() = default;
	CommandFactory(const CommandFactory& other) = delete;
	CommandFactory& operator=(const CommandFactory& other) = delete;
public:
	static CommandFactory& getInstance();
	static Command* createCommand(const MyString& command);
};

