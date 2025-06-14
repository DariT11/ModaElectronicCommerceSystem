#pragma once
#include "MyString.h"

class Transaction
{
	MyString clientEgn;
	double amount;
	MyString type;

public:
	Transaction() = default;
	Transaction(const MyString& clientEgn, double amount, const MyString& type);

	void print() const;

	const MyString& getClientEgn() const;
	double getAmount() const;
	const MyString& getType() const;
};

