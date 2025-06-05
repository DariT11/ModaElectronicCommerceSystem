#pragma once
#include "Item.h"

class ProductManager
{
public:
	void listProducts(Item* const* items, size_t count) const;
	void filterByRating(Item** items, size_t count) const;
	void viewProduct(Item* const* items, size_t count, unsigned id) const;
};