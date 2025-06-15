#pragma once
#include "Command.h"
#include "ItemsCatalog.h"

class ListItemsCommand : public Command
{
    ItemsCatalog& catalog;

public:
    ListItemsCommand(ItemsCatalog& catalog);
    void execute() override;
};

