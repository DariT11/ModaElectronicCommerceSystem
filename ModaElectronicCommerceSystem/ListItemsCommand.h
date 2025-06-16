#pragma once
#include "Command.h"
#include "ItemsCatalog.h"
class System;

class ListItemsCommand : public Command
{
    //ItemsCatalog& catalog;

public:
    //ListItemsCommand(ItemsCatalog& catalog);
    ListItemsCommand();
    void execute(System& system) override;
};

