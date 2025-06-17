#pragma once
#include "Item.h"

class CartItem
{
public:
	Item* item;
	unsigned quantity;

	CartItem() = default;
	CartItem(Item* item, unsigned quantity);

	void increaseQuantity(unsigned q);
	void decreaseQuantity(unsigned q);

	Item* getItemPointer() const;
	unsigned getQuantity() const;
};