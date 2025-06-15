#include "ListItemsCommand.h"

ListItemsCommand::ListItemsCommand(ItemsCatalog& catalog)
	:catalog(catalog)
{
}

void ListItemsCommand::execute()
{
	catalog.listOfItems();
}
