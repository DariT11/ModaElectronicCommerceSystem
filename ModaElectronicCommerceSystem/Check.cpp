#include "Check.h"

Check::Check(const MyString& code, double amount)
    :code(code), amount(amount)
{
}

const MyString& Check::getCode() const
{
    return code;
}

double Check::getAmount() const
{
    return amount;
}
