#include "User.h"
#include "Command.h"

User::User(const MyString& username, const MyString& egn, const MyString& password) :username(username), egn(egn), password(password)
{

}

void User::viewProfile() const
{

}

void User::logout()
{

}

const MyString& User::getUsername() const
{
	return username;
}

const MyString& User::getPassword() const
{
	return password;
}

void User::executeCommand(Command* command)
{
	command->execute();
}

const MyString& User::getEgn() const
{
	return egn;
}

void User::help() const
{

}