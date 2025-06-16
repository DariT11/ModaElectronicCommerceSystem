#include "FinanceManager.h"
using namespace std;

FinanceManager::FinanceManager(Admin& admin)
	:admin(admin)
{
}

void FinanceManager::checkBalance(const Client& client) const
{
	cout << "Client balance: " << client.getWallet() << " BGN" << endl;
	cout << "Client points: " << client.getPoints() << endl;
}

void FinanceManager::redeem(Client& client, const MyString& code, Admin& admin) const
{
	client.redeemCheck(code, admin);
}

Admin& FinanceManager::getAdmin()
{
	return admin;
}
