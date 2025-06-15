#include "LogOutCommand.h"
using namespace std;

/*LogOutCommand::LogOutCommand(User* user)
	:user(user)
{
}*/

void LogOutCommand::execute(System& system)
{
	User* user = system.getCurrentUser();
	if (user)
	{
		user->logÎut();
		system.setCurrentUser(nullptr);
	}
	else
	{
		cout << "No user is logged in! :(" << endl;
	}
}
