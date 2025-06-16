#include "ViewProductCommand.h"
#include "System.h"

ViewProductCommand::ViewProductCommand(unsigned id)
	:id(id)
{
}

void ViewProductCommand::execute(System& system)
{
	system.getItemsCatalog().viewItem(id);
}
