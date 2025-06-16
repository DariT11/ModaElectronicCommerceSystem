#include "AddItemCommand.h"
#include "System.h"

using namespace std;

AddItemCommand::AddItemCommand(const MyString& name, double price, unsigned quantity, const MyString& description)
    :name(name), price(price), quantity(quantity)
{
}

void AddItemCommand::execute(System& system)
{
    User* user = system.getCurrentUser();
    if (!user || user->getRole() != Role::Bussiness)
    {
        cout << "Only business users can add items!" <<  endl;
        return;
    }

    BusinessProfile* business = dynamic_cast<BusinessProfile*>(user);
    if (!business)
    {
        cout << "Error: Current user is not a business profile! :(" << endl;
        return;
    }
    business->addItem(name, price, quantity, description);
}
