#include "RejectRefundCommand.h"
#include "System.h"

using namespace std;

RejectRefundCommand::RejectRefundCommand(size_t index, const MyString& reason)
	:index(index), reason(reason)
{
}

void RejectRefundCommand::execute(System& system)
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
    business->rejectRefund(index, reason);
}
