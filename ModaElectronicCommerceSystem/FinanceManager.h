#pragma once
#include "Client.h"
#include "MyString.h"

class FinanceManager
{
	Admin& admin;
public:
	void checkBalance(const Client& client) const;
	void redeem(Client& client, const MyString& code, Admin& admin) const;
};