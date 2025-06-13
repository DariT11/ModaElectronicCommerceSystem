#pragma once
#include <ctime>
#include "Item.h"
#include "OrderStatus.h"
#include "Cart.h"
class Client;
using namespace Constants;

class Order
{
	static unsigned nextOrderId;
	unsigned orderId;

	double price = 0.0;
	unsigned rewardPoints = 0;
	Cart cart;
	OrderStatus status;
	time_t createdAt;

	Client* client = nullptr;

public:
	Order() = default;
	Order(const Cart& cart, Client* client);

	unsigned getId() const;
	double getPrice() const;
	unsigned getRewardPoints() const;
	OrderStatus getOrderStatus() const;
	time_t getCreationTime() const;
	Client* getClient() const;

	void markAsShipped();
	void markAsDelivered();

	bool isShipped() const;
	bool isDelivered() const;

	void print() const;
	const char* statusToString() const;
};