#include "FilterAlphabeticallyCommand.h"

FilterAlphabeticallyCommand::FilterAlphabeticallyCommand(ItemsCatalog& catalog)
	:catalog(catalog)
{

}

void FilterAlphabeticallyCommand::execute(System& system)
{
	catalog.filterAlphabetically();
}
