#include "FilterByPriceCommand.h"

FilterByPriceCommand::FilterByPriceCommand(ItemsCatalog& catalog)
	:catalog(catalog)
{
}

void FilterByPriceCommand::execute()
{
	catalog.filterByPrice();
}
