#pragma once
#include "Constants.h"
#include "MyString.h"
class Command;
using namespace Constants;

class User
{
protected:
	MyString username;
	MyString egn;
	MyString password;

public:
	User(const MyString& username, const MyString& egn, const MyString& password);

	virtual ~User() = default;

	virtual void logout();
	virtual void help() const;
	virtual void viewProfile() const;

	const MyString& getUsername() const;
	const MyString& getEgn() const;
	const MyString& getPassword() const;

	void executeCommand(Command* command);
};