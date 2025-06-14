#pragma once
#include "User.h"
#include "MyVector.hpp"
#include "Transaction.h"
#include "Check.h"
#include "Client.h"

class Admin : public User
{
	MyVector<Transaction> transactions;
	MyVector<Check> issuedChecks;

public:
	Admin(const MyString& username, const MyString& egn, const MyString& password);
	
	void sendCheck(double amount, const MyString& code, Client& client);
	void viewTransactions() const;
	void clientInsights(const MyVector<Client>& clients) const;
	void addTransaction(const Transaction& transaction);

	void executeCommand(Command* command);
};

