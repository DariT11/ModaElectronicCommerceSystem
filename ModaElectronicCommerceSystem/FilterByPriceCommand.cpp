#include "FilterByPriceCommand.h"
#include "System.h"

FilterByPriceCommand::FilterByPriceCommand(bool ascending)
	:ascending(ascending)
{
}

void FilterByPriceCommand::execute(System& system)
{
	system.getItemsCatalog().filterByPrice(ascending);
}
