#include "Admin.h"
using namespace std;

Admin::Admin(const MyString& username, const MyString& egn, const MyString& password)
	:User(username,egn,password)
{
}

void Admin::sendCheck(double amount, const MyString& code, Client& client)
{
	Check check(code, amount);
	issuedChecks.push_back(check);
	client.addCheck(check);
	cout << "Check: " << code << " for the amout of: " << amount << " was sent to: " 
		<< client.getUsername() << endl;
}

void Admin::viewTransactions() const
{
	for (size_t i = 0; i < transactions.getSize(); i++)
	{
		transactions.operator[](i).print();
	}
}

void Admin::clientInsights(const MyVector<Client>& clients) const
{
	for (size_t i = 0; i < clients.getSize(); i++)
	{
		const Client& cl = clients.operator[](i);
		cout << "Client: " << cl.getUsername() << endl;
		cout << "Orders: " << cl.getOrderHistory().getSize() << endl;

		double totalSpent = 0;
		for (size_t j = 0; j < cl.getOrderHistory().getSize(); j++)
		{
			totalSpent += cl.getOrderHistory().operator[](j).getPrice();
		}
		cout << "Total money spent: " << totalSpent << "BGN" << endl;
	}
}

void Admin::addTransaction(const Transaction& transaction)
{
	transactions.push_back(transaction);
}