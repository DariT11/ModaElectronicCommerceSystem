#include "FilterAlphabeticallyCommand.h"
#include "System.h"

FilterAlphabeticallyCommand::FilterAlphabeticallyCommand()
{

}

void FilterAlphabeticallyCommand::execute(System& system)
{
	system.getItemsCatalog().filterAlphabetically();
}
