#pragma once
#include "User.h"
#include "MyVector.hpp"
#include "Transaction.h"
#include "Check.h"
#include "Client.h"
#include "Role.h"
#include <fstream>
class System;

class Admin : public User
{
	MyVector<Transaction> transactions;
	MyVector<Check> issuedChecks;

public:
	Admin();
	Admin(const MyString& username, const MyString& egn, const MyString& password, Role role);
	
	void sendCheck(double amount, const MyString& code, Client& client);
	void viewTransactions() const;
	void clientInsights(const MyVector<Client>& clients) const;
	void addTransaction(const Transaction& transaction);

	void executeCommand(Command* command, System& system);
};

