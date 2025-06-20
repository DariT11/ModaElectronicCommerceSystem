#include "Client.h"
#include "Order.h"
#include "Transaction.h"
#include "Admin.h"
#include <stdexcept>
#include <fstream>
using namespace std;

Client::Client() : User(Role::Client)
{}

Client::Client(const MyString& username, const MyString& egn, const MyString& password, unsigned points, double wallet, const Cart& cart, Role role)
    :User(username, egn, password, role), points(points), wallet(wallet), cart(cart)
{

}

Cart& Client::getCart()
{
    return cart;
}

double Client::getWallet() const
{
    return wallet;
}

unsigned Client::getPoints() const
{
    return points;
}

Role Client::getRole() 
{
    return role;
}

MyString Client::getUsername() const
{
    return User::getUsername();
}

const MyVector<Order> Client::getOrderHistory() const
{
    return orderHistory;
}

const MyVector<Check> Client::getReceivedChecks() const
{
    return receivedChecks;
}

void Client::deductFromWallet(double amount)
{
    wallet -= amount;
}

void Client::addToWallet(double amount)
{
    wallet += amount;
}

void Client::deductPoints(unsigned points)
{
    points -= points;
}

void Client::addPoints(unsigned points)
{
    points += points;
}

void Client::placeOrder()
{
    double total = cart.calculateTotalWithDiscount();
    if (total > wallet)
    {
        throw invalid_argument("Insufficient availability! Please charge! :)");
    }

    Order newOrder = cart.toOrder(this);
    deductFromWallet(total);
    orderHistory.push_back(newOrder);
    cart.clear();

    cout << "Successful order! :)" << endl;
    cout << "Withdrawn money: " << total << " BGN" << endl;
}

void Client::removeOrder(unsigned orderId)
{
    for (size_t i = 0; i < orderHistory.getSize(); i++)
    {
        if (orderHistory.operator[](i).getId() == orderId)
        {
            orderHistory.erase(i);
            cout << "This order has been deleted from order history! :)" << endl;
            return;
        }
    }
}

void Client::requestRefund(size_t orderIndex, BusinessProfile& business)
{
    if (orderIndex >= orderHistory.getSize())
    {
        throw out_of_range("Invalid order number! :(");
    }

    Order& order = orderHistory.operator[](orderIndex);
    if (!order.isDelivered())
    {
        cout << "Only delivered orders can be refunded! :)" << endl;
        return;
    }

    business.addRefundRequest(&order);

    cout << "Return request submitted! :)" << endl;
}

void Client::addCheck(const Check& check)
{
    receivedChecks.push_back(check);
}

bool Client::redeemCheck(const MyString& code, Admin& admin)
{
    for (size_t i = 0; i < receivedChecks.getSize(); i++)
    {
        if (receivedChecks.operator[](i).getCode() == code)
        {
            double amount = receivedChecks.operator[](i).getAmount();
            addToWallet(amount);
            admin.addTransaction(Transaction(getEgn(), amount, "Check"));
            receivedChecks.erase(i);
            cout << "This check has been cashed! :)" << endl;
            return true;
        }
    }

    cout << "Invalid check code! :(" << endl;
    return false;
}

void Client::executeCommand(Command* command, System& system)
{
    command->execute(system);
}

void Client::serialize(std::ofstream& out) const
{
    User::serialize(out);
    out << wallet << endl;
    out << points << endl;
}

void Client::deserialize(std::ifstream& in) 
{
    User::deserialize(in);
    in >> wallet;
    in >> points;
}
