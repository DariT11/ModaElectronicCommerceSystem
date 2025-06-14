#include "Transaction.h"
using namespace std;

Transaction::Transaction(const MyString& clientEgn, double amount, const MyString& type)
	:clientEgn(clientEgn), amount(amount), type(type)
{
}

void Transaction::print() const
{
	cout << "Client: " << clientEgn << endl;
	cout << "Type: " << type << endl;
	cout << "Amount: " << amount << endl;
}

const MyString& Transaction::getClientEgn() const
{
	return clientEgn;
}

double Transaction::getAmount() const
{
	return amount;
}

const MyString& Transaction::getType() const
{
	return type;
}
