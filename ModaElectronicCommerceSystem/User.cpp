#include "User.h"
#include "Command.h"
#include <stdexcept>
using namespace std;

User::User(const MyString& username, const MyString& egn, const MyString& password, Role role)
	:role(role)
{
	setUsername(username);
	setEgn(egn);
	setPassword(password);
}

void User::viewProfile() const
{
	cout << "User: " << username << endl;
	cout << "EGN: " << egn << endl;
}

void User::logÎut()
{
	cout << "User: " << username << " logged out! :)" << endl;
}

const MyString& User::getUsername() const
{
	return username;
}

void User::setUsername(const MyString& username)
{
	if (username.isEmpty())
	{
		throw invalid_argument("Username must contain at least 1 character! :)");
	}
	else if (username.getSize() > 30)
	{
		throw invalid_argument("Too long username :)");
	}

	this->username = username;
}

const MyString& User::getPassword() const
{
	return password;
}

void User::setPassword(const MyString& password)
{
	/*if (password.getSize() < 4 || password.getSize() > 20)
	{
		throw invalid_argument("Password must be between 4 and 20 characters! :)");
	}j*/

	this->password = password;
}

Role User::getRole() const
{
	return role;
}

void User::executeCommand(Command* command, System& system)
{
	command->execute(system);
}

const MyString& User::getEgn() const
{
	return egn;
}

void User::setEgn(const MyString& egn)
{
	/*if (egn.getSize() != 9)
	{
		throw invalid_argument("EGN must contain exactly 10 characters! :)");
	}
    */
	this->egn = egn;
}

void User::help() const
{
	cout << "Accessible commands for every user: (logout, help, view-profile)" << endl;
}

User::User(Role role)
{
	this->role = role;
}

void User::serialize(std::ofstream& out) const 
{
	out << (int)role << endl;
	out << username << endl;
	out << egn << endl;
	out << password << endl;
}

void User::deserialize(std::ifstream& in)
{
	in >> username;
	in >> egn;
	in >> password;
}

