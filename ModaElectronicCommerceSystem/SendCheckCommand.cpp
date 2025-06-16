#include "SendCheckCommand.h"
#include "System.h"

using namespace std;

void SendCheckCommand::execute(System& system)
{
    User* user = system.getCurrentUser();
    if (!user || user->getRole() != Role::Administrator)
    {
        cout << "Only admins can send checks!" << endl;
        return;
    }

    Admin* admin = dynamic_cast<Admin*>(user);
    if (!admin)
    {
        cout << "Error: current user is not a valid admin!" << endl;
        return;
    }

    double amount;
    MyString code;

    MyString username;
    cout << "Enter client's username: ";
    cin >> username;

    User* found = system.findUserByUsername(username);
    if (!found || found->getRole() != Role::Client)
    {
        cout << "Client with this username was not found!" << endl;
        return;
    }

    Client* client = dynamic_cast<Client*>(found);
    if (!client)
    {
        cout << "Error: Found user is not a valid Client!" << endl;
        return;
    }

    cout << "Enter check amount: ";
    cin >> amount;
    cout << "Enter check code: ";
    cin >> code;

    admin->sendCheck(amount, code, *client);
}
