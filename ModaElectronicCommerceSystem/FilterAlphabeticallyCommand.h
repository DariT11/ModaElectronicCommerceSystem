#pragma once
#include "Command.h"
#include "ProductManager.h"
#include "Item.h"

class FilterAlphabeticallyCommand :public Command
{
    ProductManager& pManager;
    Item** items;
    size_t itemsCount;

public:
    FilterAlphabeticallyCommand(ProductManager& pManager, Item** items, size_t itemsCount);
    void execute() override;
};

