#include "ViewProductCommand.h"

ViewProductCommand::ViewProductCommand(ProductManager& pManager, Item** items, size_t itemsCount, unsigned id)
	:pManager(pManager),items(items), itemsCount(itemsCount), id(id)
{

}

void ViewProductCommand::execute()
{
	pManager.viewProduct(items, itemsCount, id);
}
