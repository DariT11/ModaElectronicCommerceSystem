#include "ViewProfileCommand.h"

ViewProfileCommand::ViewProfileCommand(User* user) :user(user)
{
}

void ViewProfileCommand::execute()
{
	if (user)
	{
		user->viewProfile();
	}
}
