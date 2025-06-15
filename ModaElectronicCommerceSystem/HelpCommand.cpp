#include "HelpCommand.h"
#include "System.h"

void HelpCommand::execute(System& system)
{
	User* user = system.getCurrentUser();
	if (user)
	{
		user->help();
	}
}
