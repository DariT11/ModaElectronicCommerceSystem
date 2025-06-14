#include "BusinessProfile.h"
#include "Client.h"
using namespace std;

BusinessProfile::BusinessProfile(const MyString& username, const MyString& egn, const MyString& password, double revenue, Role role)
    :User(username, egn, password), revenue(revenue), role(role)
{
}

BusinessProfile::BusinessProfile(const MyString& username, const MyString& egn, const MyString& password, const MyVector<Item>& items,
    const MyVector<Order>& orders, const MyVector<Order*>& refundRequests, Role role)
    :User(username,egn,password), items(items), orders(orders), refundRequests(refundRequests), role(role)
{

}

void BusinessProfile::addItem(const MyString& name, double price, unsigned quantity, const MyString& description)
{
    items.push_back(Item(name, description, price, quantity));
    cout << "Item: " << name << "is added! :)" << endl;
}

void BusinessProfile::removeItem(const MyString& name)
{
    for (size_t i = 0; i < items.getSize(); i++)
    {
        if (items.operator[](i).getName() == name)
        {
            items.erase(i);
            cout << "Item: " << name << "was removed! :)" << endl;
            return;
        }
    }
    throw invalid_argument("Item with this name was not found! :( Please try again!");
}

void BusinessProfile::listItems() const
{
    if (items.empty())
    {
        cout << "There is no items yet! :(" << endl;
        return;
    }

    for (size_t i = 0; i < items.getSize(); i++)
    {
        cout << "[" << i + 1 << "] Item:" << items.operator[](i).getName() << endl;
        cout << "Price: " << items.operator[](i).getPrice() << endl;
        cout << "Quantity: " << items.operator[](i).getQuantity() << endl;
        cout << "Description: " << items.operator[](i).getDescription() << endl;
    }
}

void BusinessProfile::listPendingOrders() const
{
    for (size_t i = 0; i < orders.getSize(); i++)
    {
        if (orders.operator[](i).getOrderStatus() == OrderStatus::Pending)
        {
            cout << i << ": ";
            orders.operator[](i).print();
        }
    }
}

void BusinessProfile::approveOrder(size_t index)
{
    if (index >= orders.getSize())
    {
        throw out_of_range("Invalid order number! :( Please try again!");
    }

    Order& order = orders.operator[](index);
    if (order.getOrderStatus() != OrderStatus::Pending)
    {
        cout << "The status of this order is not pending! :)" << endl;
        return;
    }

    order.markAsShipped();
    revenue += order.getPrice();

    cout << "Order was approved and shipped! :)" << endl;
}

void BusinessProfile::rejectOrder(size_t index, const MyString& reason)
{
    if (index >= orders.getSize())
    {
        throw out_of_range("Invalid order number! :( Please try again!");
    }

    Order& order = orders.operator[](index);
    if (order.getOrderStatus() != OrderStatus::Pending)
    {
        cout << "The status of this order is not pending! :)" << endl;
        return;
    }

    Client* client = order.getClient();
    if (client)
    {
        client->addToWallet(order.getPrice());
        client->addPoints(order.getRewardPoints());
        cout << "The money and points have been returned to the client! :)";
    }

    orders.erase(index);
    cout << "This order was cancelled and deleted, because of: " << reason << " :(" << endl;
}

void BusinessProfile::listOrders() const
{
    for (size_t i = 0; i < orders.getSize(); i++)
    {
        cout << "[" << i + 1<< "]";
        orders.operator[](i).print();
    }
}

void BusinessProfile::listBestSellers() const
{
    if (items.empty())
    {
        cout << "There are still no items in this business account! :(" << endl;
        return;
    }

    MyVector<Item> sorted = items;
    for (size_t i = 0; i < sorted.getSize(); i++)
    {
        for (size_t j = i + 1; j < sorted.getSize(); j++)
        {
            if (sorted.operator[](j).getSalesCount() > sorted.operator[](i).getSalesCount())
            {
                Item temp = sorted.operator[](i);
                sorted.operator[](i) = sorted.operator[](j);
                sorted.operator[](j) = temp;
            }
        }
    }

    cout << "Bestsellers: " << endl;
    for (size_t i = 0; i < sorted.getSize(); i++)
    {
        cout << "Item: " << sorted.operator[](i).getName() << "is bought: " << sorted.operator[](i).getSalesCount()
            << "times!";
    }
}

void BusinessProfile::readRevenue() const
{
    cout << "Revenue: " << revenue << "BGN" << endl;
}

const MyString& BusinessProfile::getUsername() const
{
    return User::getUsername();
}

double BusinessProfile::getRevenue() const
{
    return revenue;
}

Role BusinessProfile::getRole() const
{
    return role;
}

void BusinessProfile::addOrder(const Order& order)
{
    orders.push_back(order);
}

void BusinessProfile::addRefundRequest(Order* order)
{
    refundRequests.push_back(order);
}

void BusinessProfile::listRefunds() const
{
    if (refundRequests.empty())
    {
        cout << "No orders to return yet!" << endl;
        return;
    }

    for (size_t i = 0; i < refundRequests.getSize(); i++)
    {
        cout << "Order: [" << i + 1 << "] ";
        refundRequests.operator[](i)->print();
        cout << endl;
    }
}

void BusinessProfile::approveRefund(size_t index) 
{
    if (index< 0 || index >= refundRequests.getSize())
    {
        throw invalid_argument("Invalid number of refund request! :( Please try again!:)");
    }

    Order* order = refundRequests.operator[](index);
    Client* client = order->getClient();

    if (!client)
    {
        throw invalid_argument("Non-existent client! :(");
    }

    client->addToWallet(order->getPrice());
    client->addPoints(order->getRewardPoints());

    const MyVector<CartItem>& items = order->getCart().getItems();
    for (size_t i = 0; i < items.getSize(); i++)
    {
        Item* item = items.operator[](i).getItemPointer();
        if (item)
        {
            item->increaseQuantity(items.operator[](i).getQuantity());
        }
    }

    client->removeOrder(order->getId());

    refundRequests.erase(index);

    cout << "Refund request approved! :)" << endl;
}

void BusinessProfile::rejectRefund(size_t index, const MyString& reason)
{
    if (index >= refundRequests.getSize())
    {
        throw out_of_range("Invalid refund request number! :( Please try again! :)");
    }

    Order* order = refundRequests.operator[](index);

    Client* client = order->getClient();
    if (client)
    {
        cout << "Refund request denied, because of " << reason << ":(" << endl;
    }

    refundRequests.erase(index);
}

void BusinessProfile::executeCommand(Command* command)
{
    command->execute();
}
