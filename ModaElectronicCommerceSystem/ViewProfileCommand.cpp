#include "ViewProfileCommand.h"

ViewProfileCommand::ViewProfileCommand(User* user) :user(user)
{
}

void ViewProfileCommand::execute(System& system)
{
	if (user)
	{
		user->viewProfile();
	}
}
