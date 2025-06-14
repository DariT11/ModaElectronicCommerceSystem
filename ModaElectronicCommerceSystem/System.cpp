#include "System.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "Client.h"
#include "Cart.h"
#include "Role.h"
#include "BusinessProfile.h"
#include "Admin.h"
#include "MyString.h"
#include "Command.h"
using namespace std;

void System::start()
{
	load("dari.txt");
	char buffer[1024];

	while (true)
	{
		cout << "> ";
		MyString command;
		cin >> command;

		if (command.isEmpty())
		{
			cout << "Invalid command! :(" << endl;
			cout << "Please try again! :)" << endl;
			//ponqkakuv nachin rekursiq
		}

		if (command == "exit")
		{
			save("dari.txt");
			cout << "Information saved! Exit!:)" << endl;
			break;
		}
		else if (command == "save")
		{
			save("dari.txt");
			cout << "Information saved! :)" << endl;
		}
		else if (command == "load")
		{
			load("dari.txt");
			cout << "Data reloaded! :)" << endl;
		}
		else if (command == "login")
		{
			MyString username, password;
			cin >> buffer;
			username = buffer;
			cin >> buffer;
			password = buffer;
			logIn(username, password);
			cin.ignore();
		}
		else if (command == "register")
		{
			MyString role, username, egn, password;
			cin >> buffer;
			role = buffer;
			cin >> buffer;
			username = buffer;
			cin >> buffer;
			egn = buffer;
			cin >> buffer;
			password = buffer;
			registerUser(role, username, egn, password);
			std::cin.ignore();
		}
		else if (currentUser)
		{
			//currentUser->executeCommand(new Command(command));
		}
		else
		{
			cout << "Please log in first! :)" << endl;
		}
		handleCommand(command);
	}
}

void System::handleCommand(const MyString& commandLine)
{
	//if()
}

void System::logIn(const MyString& username, const MyString& password)
{
	User* user = findUserByUsername(username);
	if (!user || user->getPassword() != password)
	{
		cout << "Wrong username or password!" << endl;
		return;
	}

	currentUser = user;
	cout << "Welcome back! :(" << endl;
}

void System::registerUser(const MyString& role, const MyString& username, const MyString& password, const MyString& egn)
{
	if (findUserByUsername(username))
	{
		cout << "User with this username already exists! :(" << endl;
		return;
	}

	if (role == "client")
	{
		users.push_back(new Client(username, egn, password, 0, 0.0, Cart(), Role::Client));
	}
	else if (role == "business")
	{
		users.push_back(new BusinessProfile(username, egn, password, 0.0, Role::Bussiness));
	}
	else if (role == "admin")
	{
		users.push_back(new Admin(username, egn, password));
	}
	else
	{
		cout << "Invalid user type!" << endl;
		return;
	}

	cout << "Successful registration! :)" << endl;
}

User* System::findUserByUsername(const MyString& username)
{
	for (size_t i = 0; i < users.getSize(); i++)
	{
		if (users.operator[](i)->getUsername() == username)
		{
			return users.operator[](i);
		}
	}

	cout << "User not found! :(" << endl;
	return nullptr;
}

void System::save(const MyString& filename) const
{
	ofstream out(filename.c_str());

	if (!out.is_open())
	{
		cout << "File did not open! :(" << endl;
		return;
	}

	out << users.getSize() << endl;

	for (size_t i = 0; i < users.getSize(); i++)
	{
		out << users.operator[](i)->getUsername().c_str() << endl;
		out << users.operator[](i)->getEgn().c_str() << endl;
		//rolq  i parola
	}

	out.close();
}

void System::load(const MyString& filename)
{
	ifstream in(filename.c_str());
	
	if (!in.is_open())
	{
		cout << "File did not open! " << endl; // posle shte hvurlq greshki 
		return;
	}

	size_t count = 0;
	in >> count;
	in.ignore();

	for (size_t i = 0; i < count; i++)
	{
		char buffer[1024];//da ne e magichesko chislo

		in.getline(buffer, 1024);
		MyString role(buffer);

		in.getline(buffer, 1024);
		MyString username(buffer);

		in.getline(buffer, 1024);
		MyString egn(buffer);

		in.getline(buffer, 1024);
		MyString password(buffer);

		if (role == "client")
		{
			users.push_back(new Client(username, egn, password, 0, 0.0, Cart(), Role::Client));
		}
		else if (role == "business")
		{
			users.push_back(new BusinessProfile(username, egn, password, 0.0, Role::Bussiness));
		}
		else if (role == "admin")
		{
			users.push_back(new Admin(username, egn, password));
		}
		else
		{
			cout << "invalid user!" << endl;
		}
	}

	in.close();
}

System::~System()
{
	for (size_t i = 0; i < users.getSize(); i++)
	{
		delete users.operator[](i);
	}
}
