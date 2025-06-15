#pragma once
#include "Constants.h"
#include "MyString.h"
#include "Role.h"
#include <fstream>

class Command;
class System;
using namespace Constants;

class User
{
protected:
	MyString username;
	MyString egn;
	MyString password;
	Role role;

public:
	User(Role role);
	User(const MyString& username, const MyString& egn, const MyString& password, Role role);

	virtual ~User() = default;

	virtual void logÎut(); 
	virtual void help() const;
	virtual void viewProfile() const;
	virtual void serialize(std::ofstream& out) const;
	virtual void deserialize(std::ifstream& in);

	void setUsername(const MyString& username);
	void setEgn(const MyString& egn);
	void setPassword(const MyString& password);

	const MyString& getUsername() const;
	const MyString& getEgn() const;
	const MyString& getPassword() const;
	Role getRole() const;

	void executeCommand(Command* command, System& system);
};