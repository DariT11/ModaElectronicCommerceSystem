#include "RedeemCommand.h"

RedeemCommand::RedeemCommand(FinanceManager& fManager, Client& client, const MyString code)
	:fManager(fManager), client(client), code(code)
{

}

void RedeemCommand::execute()
{
	fManager.redeem(client, code);
}