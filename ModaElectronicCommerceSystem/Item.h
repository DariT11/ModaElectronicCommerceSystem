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

public:
	Item() = default;
	Item(const MyString& name, double price, unsigned quantity,
		const MyString& description, double rating, size_t salesCount);
	Item(const MyString& name, const MyString& description, double price, unsigned quantity);
	
	virtual ~Item() = default;

	virtual void view() const;//ne e zaduljitelno da sa virtualni
	virtual void printDetails() const;
	bool purchase(unsigned count);
	void updateAvailability();
	void increaseQuantity(unsigned amount);

	void setName(const MyString& name);
	void setPrice(double price);
	void setQuantity(unsigned quantity);
	void setDescription(const MyString& name);
	void setRating(double rating);
    //availability seter

	unsigned getId() const;
	const MyString& getName() const;
	double getPrice() const;
	unsigned getQuantity() const;
	const MyString& getDescription() const;
	double getRating() const;
	bool getAvailability() const;
	size_t getSalesCount() const;
};