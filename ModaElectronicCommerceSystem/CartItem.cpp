#include "CartItem.h"

CartItem::CartItem(Item* item, unsigned quantity)
	:item(item), quantity(quantity)
{
}

Item* CartItem::getItemPointer() const
{
	return item;
}

unsigned CartItem::getQuantity() const
{
	return quantity;
}
