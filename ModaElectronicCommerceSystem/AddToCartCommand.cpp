#include "AddToCartCommand.h"
#include "Item.h"

AddToCartCommand::AddToCartCommand(Client& client, ItemsCatalog& catalog, unsigned itemId, unsigned quantity)
	:client(client), catalog(catalog), itemId(itemId), quantity(quantity)
{

}

void AddToCartCommand::execute(System& system)
{
	Item* item = catalog.getItemById(itemId);
	if (item)
	{
		client.getCart().addItem(*item, quantity);
	}
}
