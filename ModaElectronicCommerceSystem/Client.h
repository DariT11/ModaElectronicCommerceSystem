#pragma once
#include "User.h"
#include "Cart.h"
#include "MyString.h"

class Client : public User
{
	unsigned points;
	double wallet;
	Cart cart;

public:
	//Client()
};