#pragma once
#include "MyVector.hpp"
#include "MyString.h"
#include "CartItem.h"
#include "Order.h"

class Cart
{
	MyVector<CartItem> items;
	double appliedDiscount = 0.0;
	bool discountApplied = false;

public:
	void addItem(const Item& item, unsigned quantity);
	void removeItem(const MyString& itemName, unsigned quantity);

	double calculateTotalWithDiscount() const;
	double calculateTotalWithoutDiscount() const;

	void applyDiscount(unsigned& clientPoints);
	void removeDiscount(unsigned& clientPoints);

	void view() const;
	void clear();

	Order toOrder() const;

	bool isDiscountApplied() const;
	double getAppliedDiscount() const;
};

