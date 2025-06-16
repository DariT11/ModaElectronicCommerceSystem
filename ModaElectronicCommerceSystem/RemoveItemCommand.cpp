#include "RemoveItemCommand.h"
#include "System.h"

using namespace std;

RemoveItemCommand::RemoveItemCommand(const MyString& name)
	:name(name)
{
}

void RemoveItemCommand::execute(System& system)
{
    User* user = system.getCurrentUser();
    if (!user || user->getRole() != Role::Bussiness)
    {
        cout << "Only business users can remove items!" << endl;
        return;
    }

    BusinessProfile* business = dynamic_cast<BusinessProfile*>(user);
    if (!business)
    {
        cout << "Error: Current user is not a business profile! :(" << endl;
        return;
    }

    business->removeItem(name);
}
