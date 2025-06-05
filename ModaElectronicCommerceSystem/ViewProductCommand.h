#pragma once
#include "Command.h"
#include "Item.h"
#include "ProductManager.h"

class ViewProductCommand: public Command
{
	ProductManager& pManager;
	Item** items;
	size_t itemsCount;
	unsigned id;

public:
	ViewProductCommand(ProductManager& pManager, Item** items, size_t itemsCount, unsigned id);
	void execute() override;
};

