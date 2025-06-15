#pragma once
#include "MyVector.hpp"
#include "Item.h"

class ItemsCatalog
{
	MyVector<Item> items;

public:
	void addItem(const Item& item);
	const MyVector<Item>& getAllItems() const;
	Item* getItemById(unsigned id);
	void listOfItems() const;
	void viewItem(unsigned id); 

	void filterByRating();
	void filterByPrice(bool ascending);
	void filterAlphabetically();
};

