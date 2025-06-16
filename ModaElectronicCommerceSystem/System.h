#pragma once
#include "MyVector.hpp"
#include "MyString.h"
#include "User.h"
#include "FinanceManager.h"

class System
{
	MyVector<User*> users;
	User* currentUser = nullptr; 

	void logIn(const MyString& username, const MyString& password);
	void registerUser(const MyString& role, const MyString& username, const MyString& password, const MyString& egn);
	User* findUserByUsername(const MyString& username);

public:
	void start();
	void handleCommand(const MyString& commandLine);
	void save(const MyString& filename) const;
	void load(const MyString& filename);

	User* getCurrentUser() const;
	void setCurrentUser(User* user);

	~System();
};

