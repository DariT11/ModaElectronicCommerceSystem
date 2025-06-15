#include "HelpCommand.h"

HelpCommand::HelpCommand(User* user) :user(user)
{
}

void HelpCommand::execute()
{
	if (user)
	{
		user->help();
	}
}
