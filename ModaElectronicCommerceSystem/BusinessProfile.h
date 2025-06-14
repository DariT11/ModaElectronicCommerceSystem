#pragma once
#include "User.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "Item.h"
#include "Order.h"
#include "Role.h"
#include "Command.h"

class BusinessProfile: public User
{
	MyVector<Item> items;
	MyVector<Order> orders;
	MyVector<Order*> refundRequests;
	double revenue = 0.0;
	Role role;

public:
	BusinessProfile(const MyString& username, const MyString& egn, const MyString& password, const MyVector<Item>& items, 
		const MyVector<Order>& orders, const MyVector<Order*>& refundRequests, Role role = Role::Bussiness);

	void addItem(const MyString& name, double price, unsigned quantity, const MyString& description);
	void removeItem(const MyString& name);
	void listItems() const;

	void listPendingOrders() const;
	void approveOrder(size_t index);
	void rejectOrder(size_t index, const MyString& reason);
	void listOrders() const;

	void listBestSellers() const;
	void readRevenue() const;

	const MyString& getUsername() const;
	double getRevenue() const;
	Role getRole() const;

	void addOrder(const Order& order);

	void addRefundRequest(Order* order);
	void listRefunds() const;
	void approveRefund(size_t index);
	void rejectRefund(size_t index, const MyString& reason);

	virtual void executeCommand(Command* command);
};

