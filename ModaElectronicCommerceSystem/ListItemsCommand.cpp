#include "ListItemsCommand.h"
#include "System.h"

/*ListItemsCommand::ListItemsCommand(ItemsCatalog& catalog)
	:catalog(catalog)
{
}*/

ListItemsCommand::ListItemsCommand()
{
}

void ListItemsCommand::execute(System& system)
{
	ItemsCatalog& catalog = system.getItemsCatalog();
	catalog.listOfItems();
}
