#include "Item.h"

void Item::updateAvailability()
{

}

Item::Item(const MyString& name, double price, unsigned quantity, const MyString& description, double rating, size_t salesCount)
    :name(name), price(price), quantity(quantity), description(description), rating(rating), salesCount(salesCount)
{
    availability = quantity > 0;
}

void Item::view() const
{
}

bool Item::isAvailable() const
{
    return false;
}

bool Item::purchase(unsigned count)
{
    return false;
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
