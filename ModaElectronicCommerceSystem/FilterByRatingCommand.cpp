#include "FilterByRatingCommand.h"

FilterByRatingCommand::FilterByRatingCommand(ProductManager& pManager, Item** items, size_t itemsCount)
	:pManager(pManager), items(items), itemsCount(itemsCount)
{

}

void FilterByRatingCommand::execute()
{
	pManager.filterByRating(items, itemsCount);
	pManager.listProducts(items, itemsCount);
}
