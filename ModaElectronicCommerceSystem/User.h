#pragma once
#include "Constants.h"
#include "MyString.h"
using namespace Constants;

class User
{
protected:
	MyString name;
	MyString egn;
	MyString password;
	//MyString userType;

public:
	User(const MyString& name, const MyString& egn, const MyString& password);

	virtual ~User() = default;

	virtual void logout();
	virtual void help() const;
	virtual void viewProfile() const;
};