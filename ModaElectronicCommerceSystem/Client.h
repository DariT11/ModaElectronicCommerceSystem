#pragma once
#include "User.h"
#include "Cart.h"
#include "Command.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "Role.h"
#include "BusinessProfile.h"
#include "Check.h"
class Admin;
class Order;

class Client : public User
{
	unsigned points;
	double wallet;
	Cart cart;
	Role role;
	MyVector<Order> orderHistory; //tova i dolnoto ne sa v konstruktura
	MyVector<Check> receivedChecks;

public:
	Client(const MyString& username, const MyString& egn, const MyString& password, unsigned points, double wallet,const Cart& cart, Role role);

	Cart& getCart();
	double getWallet() const;
	unsigned getPoints() const;
	Role getRole();
	MyString getUsername() const;
	const MyVector<Order> getOrderHistory() const;
	const MyVector<Check> getReceivedChecks() const;

	void deductFromWallet(double amount);
	void addToWallet(double amount);
	void deductPoints(unsigned points);
	void addPoints(unsigned points);

	void placeOrder();
	void removeOrder(unsigned orderId);

	void requestRefund(size_t orderIndex, BusinessProfile& business);

	void addCheck(const Check& check);
	bool redeemCheck(const MyString& code, Admin& admin);

	void executeCommand(Command* command);
};