#pragma once
#include "MyString.h"

class Item
{
protected:
	static unsigned nextId;
	unsigned id;

	MyString name;
	double price;
	unsigned quantity;
	MyString description;
	double rating;
	bool available;
	//size_t salesCount

	void updateAvailability();

public:
	Item(const MyString& name, double price, unsigned quantity,
		const MyString& description, double rating);
	
	virtual ~Item() = default;

	virtual void view() const;
	bool isAvailable() const;
	bool purchase(unsigned count);
};