#include "Item.h"
#include <stdexcept>
using namespace std;

unsigned Item::nextId = 1;

void Item::updateAvailability()
{
    availability = quantity > 0;
}

Item::Item(const MyString& name, double price, unsigned quantity, const MyString& description, double rating, size_t salesCount)
    :name(name), price(price), quantity(quantity), description(description), rating(rating), salesCount(salesCount)
{
    id = nextId++;
    availability = quantity > 0;
}

void Item::view() const
{
    cout << "Item number: " << id << " | " 
    << "Name:" << name.c_str() << " | "
    << "Price: " << price << " BGN " << " | "
    << "Rating: " << rating << "stars " << " | "
    << "Availability " <<( (availability) ? "Yes:) " : "No:( " ) << std::endl;
}

void Item::printDetails() const
{
    cout << "Item number: " << id << endl;
    cout << "Name: " << name.c_str() << endl;
    cout << "Price: " << price << " BGN " << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Description: " << description.c_str() << endl;
    cout << "Rating: " << rating << "stars " << endl;
    cout << "Availability " << ((availability) ? "Yes:) " : "No:( ") << endl;
    cout << "Number of sales: " << salesCount << endl;
}

bool Item::purchase(unsigned count)
{
    if (!availability)
    {
        throw std::out_of_range("This product is out of stock! :(");
    }

    if (quantity < count)
    {
        throw std::out_of_range("Insufficient availability! :)");
    }
    
    quantity -= count;
    updateAvailability();

    return price * count;
}

unsigned Item::getId() const
{
    return id;
}

const MyString& Item::getName() const
{
    return name;
}

double Item::getPrice() const
{
    return price;
}

unsigned Item::getQuantity() const
{
    return quantity;
}

const MyString& Item::getDescription() const
{
    return description;
}

double Item::getRating() const
{
    return rating;
}

bool Item::getAvailability() const
{
    return availability;
}

size_t Item::getSalesCount() const
{
    return salesCount;
}
