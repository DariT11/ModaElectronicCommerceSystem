#include "FilterByRatingCommand.h"

FilterByRatingCommand::FilterByRatingCommand(ItemsCatalog& catalog)
	:catalog(catalog)
{
}

void FilterByRatingCommand::execute(System& system)
{
	catalog.filterByRating();
}
