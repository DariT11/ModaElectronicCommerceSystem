#include "FilterByRatingCommand.h"

FilterByRatingCommand::FilterByRatingCommand(ItemsCatalog& catalog)
	:catalog(catalog)
{
}

void FilterByRatingCommand::execute()
{
	catalog.filterByRating();
}
