#include "CartItem.h"

CartItem::CartItem(Item* item, unsigned quantity)
	:item(item), quantity(quantity)
{
}

void CartItem::increaseQuantity(unsigned q)
{
	quantity += q;
}

void CartItem::decreaseQuantity(unsigned q)
{
	if (q >= quantity)
	{
		quantity = 0;
	}
	else
	{
		quantity -= q;
	}
}

Item* CartItem::getItemPointer() const
{
	return item;
}

unsigned CartItem::getQuantity() const
{
	return quantity;
}
