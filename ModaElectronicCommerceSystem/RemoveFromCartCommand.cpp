#include "RemoveFromCartCommand.h"

RemoveFromCartCommand::RemoveFromCartCommand(Client& client,MyString& itemName, unsigned quantity)
	:client(client), itemName(itemName), quantity(quantity)
{

}

void RemoveFromCartCommand::execute()
{
	//client.GetCart().removeItem(itemName, quantity);
}
