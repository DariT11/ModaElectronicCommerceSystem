#include "CheckBalanceCommand.h"

CheckBalanceCommand::CheckBalanceCommand(FinanceManager& fManager, Client& client)
	:fManager(fManager), client(client)
{

}

void CheckBalanceCommand::execute()
{
	fManager.checkBalance(client);
}
