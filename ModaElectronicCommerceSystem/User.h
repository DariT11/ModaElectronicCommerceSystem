#pragma once
#include "Constants.h"
#include "MyString.h"
using namespace Constants;

class User
{
protected:
	MyString username;
	MyString egn;
	MyString password;
	//MyString userType;

public:
	User(const MyString& username, const MyString& egn, const MyString& password);

	virtual ~User() = default;

	virtual void logout();
	virtual void help() const;
	virtual void viewProfile() const;

	MyString getUsername() const;
	MyString getEgn() const;
};