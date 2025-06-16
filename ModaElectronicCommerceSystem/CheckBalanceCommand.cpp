#include "CheckBalanceCommand.h"
#include "System.h"

CheckBalanceCommand::CheckBalanceCommand()
{
}

void CheckBalanceCommand::execute(System& system)
{
    Client* client = dynamic_cast<Client*>(system.getCurrentUser());
    if (!client)
    {
        std::cerr << "No client is currently logged in!" << std::endl;
        return;
    }

    std::cout << "Wallet Balance: " << client->getWallet() << " BGN" << std::endl;
    std::cout << "Reward Points: " << client->getPoints() << std::endl;
}
