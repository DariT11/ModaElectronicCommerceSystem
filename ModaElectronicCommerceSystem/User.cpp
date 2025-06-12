#include "User.h"

User::User(const MyString& username, const MyString& egn, const MyString& password) :username(username), egn(egn), password(password)
{

}

void User::viewProfile() const
{

}

void User::logout()
{

}

MyString User::getUsername() const
{
	return username;
}

MyString User::getEgn() const
{
	return egn;
}

void User::help() const
{

}