#include "AddToCartCommand.h"
#include "Item.h"
#include "System.h"

AddToCartCommand::AddToCartCommand(unsigned itemId, unsigned quantity)
	:itemId(itemId), quantity(quantity)
{

}

void AddToCartCommand::execute(System& system)
{
	User* user = system.getCurrentUser();
	if (!user || user->getRole() != Role::Client)
	{
		std::cout << "Only logged-in clients can add items to the cart!" << std::endl;
		return;
	}

	Client* client = dynamic_cast<Client*>(user);
	if (!client)
	{
		std::cout << "Error: Current user is not a client profile!" << std::endl;
		return;
	}

	Item* item = system.getItemsCatalog().getItemById(itemId);
	if (!item)
	{
		std::cout << "Item with ID " << itemId << " not found!" << std::endl;
		return;
	}

	client->getCart().addItem(*item, quantity);
}
