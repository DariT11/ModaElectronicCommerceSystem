#include "Item.h"
#include <stdexcept>
using namespace std;

unsigned Item::nextId = 1;

void Item::updateAvailability()
{
    availability = quantity > 0;
}

void Item::setName(const MyString& name)
{
    if (name.isEmpty())
    {
        throw invalid_argument("Name must have at least one character! Please enter new name! :)");
    }

    if (name.getSize() > 50)
    {
        throw invalid_argument("This name is too long! Please enter new name! :)");
    }

    this->name = name;
}

void Item::setPrice(double price)
{
    if (price < 0)
    {
        throw invalid_argument("Invalid price! Please enter new price :)");
    }

    this->price = price;
}

void Item::setQuantity(unsigned quantity)
{
    this->quantity = quantity;
}

void Item::setDescription(const MyString& name)
{
    if (name.isEmpty())
    {
        throw invalid_argument("Description must have at least one character! Please enter new description! :)");
    }

    if (name.getSize() > 500)
    {
        throw invalid_argument("This description is too long! Please enter new description! :)");
    }

    this->description = description;
}

void Item::setRating(double rating)
{
    if (rating < 0 || rating > 5)
    {
        throw invalid_argument("Invalid rating! Please rate this product with number between 0 and 5! :)");
    }

    this->rating = rating;
}

Item::Item(const MyString& name, double price, unsigned quantity, const MyString& description, double rating, size_t salesCount)
    :name(name), price(price), quantity(quantity), description(description), rating(rating), salesCount(salesCount)
{
    id = nextId++;
    availability = quantity > 0;
}

Item::Item(const MyString& name, const MyString& description, double price, unsigned quantity)
    :name(name), description(description), price(price), quantity(quantity)
{
    
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