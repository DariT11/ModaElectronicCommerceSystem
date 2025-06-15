#include "ViewProfileCommand.h"
#include "System.h"

void ViewProfileCommand::execute(System& system)
{
	User* user = system.getCurrentUser();
	if (user)
	{
		user->viewProfile();
	}
}
