#include "Cart.h"

void Cart::addItem(const Item& item, unsigned quantity)
{
}

void Cart::removeItem(const MyString& itemName, unsigned quantity)
{
}

double Cart::calculateTotalWithDiscount() const
{
    return 0.0;
}

double Cart::calculateTotalWithoutDiscount() const
{
    return 0.0;
}

void Cart::applyDiscount(unsigned& clientPoints)
{
}

void Cart::removeDiscount(unsigned& clientPoints)
{
}

void Cart::view() const
{
}

void Cart::clear()
{
}

Order Cart::toOrder() const
{
    return Order();
}

bool Cart::isDiscountApplied() const
{
    return discountApplied;
}

double Cart::getAppliedDiscount() const
{
    return appliedDiscount;
}
