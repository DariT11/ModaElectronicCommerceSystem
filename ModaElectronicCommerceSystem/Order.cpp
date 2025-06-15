#include "Order.h"
#include "Cart.h"
#include <ctime>
using namespace std;

unsigned Order::nextOrderId = 1;

Order::Order(const Cart& cart, Client* client)
    :orderId(nextOrderId++), cart(cart),client(client), price(cart.calculateTotalWithDiscount()), status(OrderStatus::Pending), createdAt(time(nullptr))
{
    
}

unsigned Order::getId() const
{
    return orderId;
}

double Order::getPrice() const
{
    return price;
}

unsigned Order::getRewardPoints() const
{
    return rewardPoints;
}

OrderStatus Order::getOrderStatus() const
{
    return status;
}

time_t Order::getCreationTime() const
{
    return createdAt;
}

void Order::markAsShipped()
{
    if (status == OrderStatus::Pending)
    {
        status = OrderStatus::Shipped;
    }
}

void Order::markAsDelivered()
{
    if (status == OrderStatus::Shipped)
    {
        status = OrderStatus::Delivered;
    }
    rewardPoints = price * 0.05;
}

bool Order::isShipped() const
{
    return status == OrderStatus::Shipped;
}

Client* Order::getClient() const
{
    return client;
}

const Cart& Order::getCart() const
{
    return cart;
}

bool Order::isDelivered() const
{
    return status == OrderStatus::Delivered;
}

void Order::print() const
{
    cout << "Îrder number: " << orderId << endl;
    cout << "Îrder price: " << orderId << "BGN" << endl;
    cout << "Reward points: " << rewardPoints << endl;
    cout << "Order status: " << statusToString() << endl;

    time_t now = time(nullptr);
    char buffer[26];
    ctime_s(buffer, sizeof(buffer), &now);
    cout << "Order created at: " << buffer << endl;
    cout << "Order items: " << endl;
    cart.view();
}

const char* Order::statusToString() const
{
    switch (status)
    {
    case OrderStatus::Pending: return "Pending"; break;
    case OrderStatus::Shipped: return "Shipped"; break;
    case OrderStatus::Delivered: return "Delivered"; break;
    default: return "Status Unknown!"; break;
    }
}
