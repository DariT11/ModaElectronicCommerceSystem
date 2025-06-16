#include "ListPandingOrdersCommand.h"
#include "System.h"

using namespace std;

void ListPandingOrdersCommand::execute(System& system)
{
    User* user = system.getCurrentUser();
    if (!user || user->getRole() != Role::Bussiness)
    {
        return;
    }

    BusinessProfile* business = dynamic_cast<BusinessProfile*>(user);
    if (!business)
    {
        cout << "Error: Current user is not a business profile! :(" << endl;
        return;
    }
    business->listPendingOrders();
}
