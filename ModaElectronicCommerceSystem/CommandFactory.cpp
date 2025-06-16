#include "CommandFactory.h"

#include "FinanceManager.h"

#include "LogOutCommand.h"
#include "ViewProfileCommand.h"
#include"CheckBalanceCommand.h"
#include "RedeemCommand.h"
#include "HelpCommand.h"
#include "ListItemsCommand.h"
#include "FilterByRatingCommand.h"
#include "FilterByPriceCommand.h"
#include "FilterAlphabeticallyCommand.h"
#include "ViewProductCommand.h"

#include "AddItemCommand.h"
#include "RemoveItemCommand.h"
#include "ListPandingOrdersCommand.h"
#include "ApproveOrderCommand.h"
#include "RejectOrderCommand.h"
#include "ListOrdersCommand.h"
#include "ListBestSellingCommand.h"
#include "ViewRevenueCommand.h"
#include "ListRefundCommand.h"
#include "ApproveRefundCommand.h"
#include "RejectRefundCommand.h"

#include "SendCheckCommand.h"
#include "CustomerInsighsCommand.h"
#include "ViewTransactionCommand.h"

using namespace std;

CommandFactory& CommandFactory::getInstance()
{
    static CommandFactory commandFactory;
    return commandFactory;
}

Command* CommandFactory::createCommand(const MyString& command)
{
    if (command == "logout")
    {
        return new LogOutCommand();
    }
    else if (command == "help") 
    {
        return new HelpCommand();
    }
    else if (command == "view_profile")
    {
        return new ViewProfileCommand();
    }
    else if (command == "check_balance")
    {
       return new CheckBalanceCommand();
    }
    else if (command == "redeem_check")
    {
        return new RedeemCommand();
    }
    else if (command == "list_products")
    {
        return new ListItemsCommand();
    }
    else if (command == "filter_by_rating")
    {
        return new FilterByRatingCommand();
    }
    else if (command == "filter_by_price")
    {
        char input;
        cout << "Choose 'a' for asc or 'd' for desc: ";
        cin >> input;
        if (input == 'a')
        {
            return new FilterByPriceCommand(true);
        }
        else
        {
            return new FilterByPriceCommand(false);
        }
    }
    else if (command == "filter_alphabetically")
    {
        return new FilterAlphabeticallyCommand();
    }
    else if (command == "view_product")
    {
        unsigned input;
        cout << "Enter product id: ";
        cin >> input;
        return new ViewProductCommand(input);
    }
    else if (command == "add_item")
    {
        MyString name, description;
        unsigned quantity;
        double price;

        cout << "Item name: ";
        cin >> name;
        cout << "Quantity: ";
        cin >> quantity;
        cout << "Price: ";
        cin >> price;
        cout << "Description: ";
        cin >> description;

        return new AddItemCommand(name, price, quantity, description);
    }
    else if (command == "remove_item")
    {
        MyString name;
        cout << "Choose name: ";
        cin >> name;
        return new RemoveItemCommand(name);
    }
    else if (command == "list_pending_orders")
    {
        return new ListPandingOrdersCommand();
    }
    else if (command == "approve_order")
    {
        size_t index;
        cout << "Choose order number: ";
        cin >> index;
        return new ApproveOrderCommand(index);
    }
    else if (command == "reject_order")
    {
        size_t index;
        cout << "Choose order number: ";
        cin >> index;
        MyString reason;
        cout << "Give a reason: ";
        cin >> reason;
        return new RejectOrderCommand(index, reason);
    }
    else if (command == "list_orders")
    {
        return new ListOrdersCommand();
    }
    else if (command == "list_best_selling_products")
    {
        return new ListBestSellingCommand();
    }
    else if (command == "view_revenue")
    {
        return new ViewRevenueCommand();
    }
    else if (command == "list_refunds")
    {
        return new ListRefundCommand();
    }
    else if (command == "approve_refund")
    {
        size_t index;
        cout << "Choose refund number: ";
        cin >> index;
        return new ApproveRefundCommand(index);
    }
    else if (command == "reject_refund")
    {
        size_t index;
        cout << "Choose refund number: ";
        cin >> index;
        MyString reason;
        cout << "Give a reason: ";
        cin >> reason;
        return new RejectRefundCommand(index, reason);
    }
    else if (command == "send_check")
    {
        return new SendCheckCommand();
    }
    else if (command == "customer_insights")
    {
        return new CustomerInsighsCommand();
    }
    else if (command == "view_transactions")
    {
        return new ViewTransactionCommand();
    }

    return nullptr;
}
