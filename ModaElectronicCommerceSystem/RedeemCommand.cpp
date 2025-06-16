#include "RedeemCommand.h"
#include "System.h"

RedeemCommand::RedeemCommand()
{

}

void RedeemCommand::execute(System& system)
{
    Client* client = dynamic_cast<Client*>(system.getCurrentUser());
    if (!client)
    {
        std::cerr << "You must be logged in as a client to redeem a check!" << std::endl;
        return;
    }
}