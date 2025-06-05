#include "FilterByPriceCommand.h"

FilterByPriceCommand::FilterByPriceCommand(ProductManager& pManager, Item** items, size_t itemsCount, bool ascending)
	:pManager(pManager), items(items), itemsCount(itemsCount), ascending(ascending)
{

}

void FilterByPriceCommand::execute()
{
	pManager.filterByPrice(items, itemsCount, ascending);
}
