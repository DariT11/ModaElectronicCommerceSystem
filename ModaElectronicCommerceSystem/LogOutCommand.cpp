#include "LogOutCommand.h"

LogOutCommand::LogOutCommand(User* user)
	:user(user)
{
}

void LogOutCommand::execute()
{
	if (user)
	{
		user->logÎut();
	}
}
