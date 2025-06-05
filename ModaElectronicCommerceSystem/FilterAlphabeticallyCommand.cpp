#include "FilterAlphabeticallyCommand.h"

FilterAlphabeticallyCommand::FilterAlphabeticallyCommand(ProductManager& pManager, Item** items, size_t itemsCount)
	:pManager(pManager), items(items), itemsCount(itemsCount)
{

}

void FilterAlphabeticallyCommand::execute()
{
	pManager.filterAlphabetically(items, itemsCount);
	pManager.listProducts(items, itemsCount);
}
