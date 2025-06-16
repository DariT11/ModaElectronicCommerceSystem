#include "System.h"
#include <fstream>
#include <iostream>
#include "Client.h"
#include "Cart.h"
#include "Role.h"
#include "BusinessProfile.h"
#include "Admin.h"
#include "MyString.h"
#include "Command.h"
#include "Constants.h"
#include "CommandFactory.h"
using namespace Constants;
using namespace std;

System::System()
	:admin(), fManager(admin)
{
}

void System::start()
{
	load("dari.txt");
	char buffer[BUFFER_SIZE];

	while (true)
	{
		try
		{
			cout << "> ";
			MyString command;
			cin >> command;

			if (command.isEmpty())
			{
				cout << "Invalid command! :(" << endl;
				cout << "Please try again! :)" << endl;
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
				cout << "Enter username: ";
				cin >> buffer;
				username = buffer;
				cout << "Enter password: ";
				cin >> buffer;
				password = buffer;
				logIn(username, password);
				cin.ignore();
			}
			else if (command == "register")
			{
				MyString role, username, egn, password;
				cout << "Enter type of user: ";
				cin >> buffer;
				role = buffer;
				cout << "Username: ";
				cin >> buffer;
				username = buffer;
				cout << "EGN: ";
				cin >> buffer;
				egn = buffer;
				cout << "Password: ";
				cin >> buffer;
				password = buffer;
				registerUser(role, username, egn, password);
				std::cin.ignore();
			}
			else
			{
				handleCommand(command);
			}
		}
		catch (std::logic_error& ex) 
		{
			std::cout << ex.what() << std::endl;
		}
		catch (std::invalid_argument& ex)
		{
			std::cout << ex.what() << std::endl;
		}
		catch (std::out_of_range& ex)
		{
			std::cout << ex.what() << std::endl;
		}
	}
}

void System::handleCommand(const MyString& command)
{
	CommandFactory& factory = CommandFactory::getInstance();
	Command* cmd = factory.createCommand(command);
	if (!cmd)
	{
		throw invalid_argument("Invalid command! :(");
	}

	cmd->execute(*this);
	delete cmd;
}

void System::logIn(const MyString& username, const MyString& password)
{
	User* user = findUserByUsername(username);
	if (!user || user->getPassword() != password)
	{
		cout << "Wrong username or password! :(" << endl;
		return;
	}

	currentUser = user;
	cout << "Welcome back! :)" << endl;
}

void System::registerUser(const MyString& role, const MyString& username, const MyString& egn, const MyString& password)
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
		users.push_back(new Admin(username, egn, password, Role::Administrator));
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

	return nullptr;
}

const MyVector<User*>& System::getAllUsers() const
{
	return users;
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
		User* user = users[i];
		user->serialize(out);
	}


	out.close();
}

void System::load(const MyString& filename)
{
	ifstream in(filename.c_str());

	if (!in.is_open())
	{
		cout << "File did not open! " << endl;
		return;
	}

	size_t count = 0;
	in >> count;
	in.ignore();

	for (size_t i = 0; i < count; i++)
	{
		int roleValue = 0;
		in >> roleValue;
		Role role = (Role)roleValue;

		switch (role)
		{
		case Role::Administrator:
		{
			Admin* admin = new Admin();
			admin->deserialize(in);
			users.push_back(admin);
			break;
		}
		case Role::Bussiness:
		{
			BusinessProfile* business = new BusinessProfile();
			business->deserialize(in);
			users.push_back(business);
			break;
		}
		case Role::Client:
		{
			Client* client = new Client();
			client->deserialize(in);
			users.push_back(client);
			break;
		}
		}
	}

	in.close();
}

FinanceManager& System::getFinanceManager()
{
	return fManager;
}

Admin& System::getAdmin()
{
	return admin;
}

ItemsCatalog& System::getItemsCatalog()
{
	return itemCatalog;
}

User* System::getCurrentUser() const
{
	return currentUser;
}

void System::setCurrentUser(User* user)
{
	currentUser = user;
}

System::~System()
{
	for (size_t i = 0; i < users.getSize(); i++)
	{
		delete users.operator[](i);
	}
}