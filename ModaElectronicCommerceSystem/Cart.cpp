#include "Cart.h"
#include "Order.h"

void Cart::addItem(Item& item, unsigned quantity)
{
    if (!item.getAvailability())
    {
        std::cout << "Item is not available!" << std::endl;
        return;
    }

    if (quantity > item.getQuantity())
    {
        std::cout << "Requested quantity exceeds available stock!" << std::endl;
        return;
    }

    for (size_t i = 0; i < items.getSize(); ++i)
    {
        if (items[i].getItemPointer()->getId() == item.getId())
        {
            items[i].getItemPointer()->increaseQuantity(quantity);
            std::cout << "Item quantity updated in cart." << std::endl;
            return;
        }
    }

    items.push_back(CartItem(&item, quantity));
    std::cout << "Item added to cart." << std::endl;
}

void Cart::removeItem(const MyString& itemName, unsigned quantity)
{
    for (size_t i = 0; i < items.getSize(); ++i)
    {
        CartItem& cartItem = items[i];
        if (cartItem.getItemPointer()->getName() == itemName)
        {
            if (quantity >= cartItem.getQuantity())
            {
                items.erase(i);
                std::cout << "Item removed completely from cart." << std::endl;
            }
            else
            {
                cartItem.decreaseQuantity(quantity);
                std::cout << "Item quantity reduced in cart." << std::endl;
            }
            return;
        }
    }

    std::cout << "Item not found in cart!" << std::endl;
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

Order Cart::toOrder(Client* client) const
{
    return Order(*this, client);
}

bool Cart::isDiscountApplied() const
{
    return discountApplied;
}

double Cart::getAppliedDiscount() const
{
    return appliedDiscount;
}

const MyVector<CartItem>& Cart::getItems() const
{
    return items;
}
