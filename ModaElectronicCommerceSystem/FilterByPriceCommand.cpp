#include "FilterByPriceCommand.h"

FilterByPriceCommand::FilterByPriceCommand(ItemsCatalog& catalog, bool ascending)
	:catalog(catalog), ascending(ascending)
{
}

void FilterByPriceCommand::execute(System& system)
{
	catalog.filterByPrice(ascending);
}
