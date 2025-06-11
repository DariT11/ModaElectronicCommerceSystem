#pragma once
#include "MyVector.hpp"
#include "Item.h"

class ItemsCatalog
{
	MyVector<Item> items;

public:
	void addItem(const Item& item);
	const MyVector<Item>& getAllItems() const;
	Item* getItemById(unsigned Id);
	void listOfItems() const;
	void viewItem() const;

	void filterByRating();
	void fileterByPrice();
	void filterAlphabetically();
};

