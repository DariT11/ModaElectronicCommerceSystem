#include "ItemsCatalog.h"
#include "Item.h"
#include <stdexcept>
using namespace std;

void ItemsCatalog::addItem(const Item& item)
{
    items.push_back(item);
}

const MyVector<Item>& ItemsCatalog::getAllItems() const
{
    return items;
}

Item* ItemsCatalog::getItemById(unsigned id)
{
    for (size_t i = 0; i < items.getSize(); i++)
    {

        if (items.operator[](i).getId() == id)
        {
            return &(items.operator[](i));
        }
    }
    return nullptr;
}

void ItemsCatalog::listOfItems() const
{
    cout << "Available products" << endl;
    for (size_t i = 0; i < items.getSize(); i++)
    {
        if (items.operator[](i).getAvailability())
        {
            cout << "Item ID: " << items.operator[](i).getId() << endl;
            cout << "Item name: " << items.operator[](i).getName() << endl;
            cout << "Item description: " << items.operator[](i).getDescription() << endl;
            cout << "Item price: " << items.operator[](i).getPrice() << endl;
            cout << "Item quantity: " << items.operator[](i).getQuantity() << endl;
            cout << "Item rating: " << items.operator[](i).getRating() << endl;
            cout << "Item sales count: " << items.operator[](i).getSalesCount() << endl;
        }
    }
}

void ItemsCatalog::viewItem(unsigned id) 
{
    Item* item = getItemById(id);

    if (!item)
    {
        throw invalid_argument("There is no item with this ID! Please choose another ID! :)");
    }

    cout << "Item ID: " << item->getId() << endl;
    cout << "Item name: " << item->getName() << endl;
    cout << "Item description: " << item->getDescription() << endl;
    cout << "Item price: " << item->getPrice() << endl;
    cout << "Item quantity: " << item->getQuantity() << endl;
    cout << "Item rating: " << item->getRating() << endl;
    cout << "Item sales count: " << item->getSalesCount() << endl;
}

void ItemsCatalog::filterByRating()
{
    //items.sort()
}

void ItemsCatalog::fileterByPrice()
{
}

void ItemsCatalog::filterAlphabetically()
{
}
