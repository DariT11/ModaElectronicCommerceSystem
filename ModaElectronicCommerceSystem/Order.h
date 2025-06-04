#pragma once
#include "Item.h"
#include "Constants.h"
using namespace Constants;

enum class Status 
{
	Pending,
	Shipped,
	Delivered
};

class Order
{
	Item* items = nullptr;
	size_t itemsCount = 0;
	size_t capacity = INITIAL_CAPACITY;

	double price = 0.0;
	unsigned rewardPoints = 0;
	Status status;
};