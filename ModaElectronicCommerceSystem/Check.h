#pragma once
#include "MyString.h"

class Check
{
	MyString code;
	double amount;

public:
	Check() = default;
	Check(const MyString& code, double amount);

	const MyString& getCode() const;
	double getAmount() const;
};

