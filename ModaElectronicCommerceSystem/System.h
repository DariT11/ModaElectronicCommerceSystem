#pragma once
#include "MyVector.hpp"
#include "MyString.h"
#include "User.h"
#include "Admin.h"
#include "ItemsCatalog.h"
#include "FinanceManager.h"

class System
{
	MyVector<User*> users;
	User* currentUser = nullptr; 

	Admin admin;              
	FinanceManager fManager;
	ItemsCatalog itemCatalog;

	void logIn(const MyString& username, const MyString& password);
	void registerUser(const MyString& role, const MyString& username, const MyString& password, const MyString& egn);

public:
	System();
	void start();
	void handleCommand(const MyString& commandLine);
	void save(const MyString& filename) const;
	void load(const MyString& filename);

	FinanceManager& getFinanceManager(); 
	Admin& getAdmin();
	ItemsCatalog& getItemsCatalog();

	User* getCurrentUser() const;
	void setCurrentUser(User* user);
	User* findUserByUsername(const MyString& username);
	const MyVector<User*>& getAllUsers() const;

	~System();
};

