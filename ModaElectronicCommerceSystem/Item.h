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
	bool availability;
	size_t salesCount;

	void updateAvailability();

public:
	Item(const MyString& name, double price, unsigned quantity,
		const MyString& description, double rating, size_t salesCount);
	
	virtual ~Item() = default;

	virtual void view() const;
	bool isAvailable() const;
	bool purchase(unsigned count);

	//Сетъри с проверки стдексепт

	unsigned getId() const;
	const MyString& getName() const;
	double getPrice() const;
	unsigned getQuantity() const;
	const MyString& getDescription() const;
	double getRating() const;
	bool getAvailability() const;
	size_t getSalesCount() const;
};