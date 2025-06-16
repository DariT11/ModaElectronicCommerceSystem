#include "FilterByRatingCommand.h"
#include "System.h"

FilterByRatingCommand::FilterByRatingCommand()
{
}

void FilterByRatingCommand::execute(System& system)
{
	system.getItemsCatalog().filterByRating();
}
