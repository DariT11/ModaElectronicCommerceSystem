#include "ViewTransactionCommand.h"
#include "System.h"

using namespace std;

void ViewTransactionCommand::execute(System& system)
{
    User* user = system.getCurrentUser();
    if (!user || user->getRole() != Role::Administrator)
    {
        return;
    }

    Admin* admin = dynamic_cast<Admin*>(user);
    if (!admin)
    {
        cout << "Error: current user is not a valid admin!" << endl;
        return;
    }

    admin->viewTransactions();
}
