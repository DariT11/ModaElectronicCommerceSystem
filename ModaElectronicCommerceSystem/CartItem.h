#pragma once
#include "Item.h"

class CartItem
{
public:
	Item item;
	unsigned quantity;

	CartItem() = default;
	CartItem(const Item& item, unsigned quantity);
};