#pragma once
#include "Command.h"
#include "ProductManager.h"
#include "Item.h"

class FilterByPriceCommand: public Command
{
	ProductManager& pManager;
	Item** items;
	size_t itemsCount;
	bool ascending;

public:
	FilterByPriceCommand(ProductManager& pManager, Item** items, size_t itemsCount, bool ascending);
	void execute() override;
};

