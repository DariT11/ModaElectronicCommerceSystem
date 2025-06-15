#include "ChekoutCommand.h"
#include "Order.h"
using namespace std;

ChekoutCommand::ChekoutCommand(Client& client, BusinessProfile& businessP)
	:client(client), businessP(businessP)
{
}

void ChekoutCommand::execute(System& system)
{
	/*double total = client.getCart().calculateTotalWithDiscount();

	if (client.getWallet() < total)
	{
		cout << "Not enough money in the wallet! Please charge! :)" << endl;
		return;
	}

	client.deductFromWallet(total);
	Order order = client.getCart().toOrder();
	businessP.receiveOrder(order);

	client.getCart().clear();*/

	cout << "Order sent for confirmation! Thank you:)" << endl;
}
