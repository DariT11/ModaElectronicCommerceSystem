#include "AddToCartCommand.h"
#include "Item.h"

AddToCartCommand::AddToCartCommand(Client& client, ItemsCatalog& catalog, unsigned itemId, unsigned quantity)
	:client(client), catalog(catalog), itemId(itemId), quantity(quantity)
{

}

void AddToCartCommand::execute()
{
	/*Item item = catalog.getItemById(itemId);
	client.getCart().addItem(item, quantity)*/
}
