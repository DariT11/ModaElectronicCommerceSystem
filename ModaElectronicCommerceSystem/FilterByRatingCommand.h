#pragma once
#include "Command.h"
#include "Item.h"
#include "ProductManager.h"

class FilterByRatingCommand:public Command
{
	ProductManager& pManager;
	Item** items;
	size_t itemsCount;

public:
	FilterByRatingCommand(ProductManager& pManager, Item** items, size_t itemsCount);
	void execute() override;
};

