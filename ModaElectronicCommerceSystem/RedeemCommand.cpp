#include "RedeemCommand.h"

RedeemCommand::RedeemCommand(FinanceManager& fManager, Client& client, Admin& admin, const MyString code)
	:fManager(fManager), client(client), admin(admin), code(code)
{

}

void RedeemCommand::execute()
{
	fManager.redeem(client, code, admin);
}