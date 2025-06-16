#include "CustomerInsighsCommand.h"
#include "System.h"

using namespace std;

void CustomerInsighsCommand::execute(System& system)
{
    Admin& admin = system.getAdmin();

    const MyVector<User*>& users = system.getAllUsers(); 
    MyVector<Client> clients;

    for (size_t i = 0; i < users.getSize(); i++) {
        if (users[i]->getRole() == Role::Client) {
            Client* client = dynamic_cast<Client*>(users[i]);
            if (client)
                clients.push_back(*client);
        }
    }

    admin.clientInsights(clients);
}
