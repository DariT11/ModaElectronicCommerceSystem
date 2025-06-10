#include "RemoveDiscountCommand.h"

RemoveDiscountCommand::RemoveDiscountCommand(Client& client)
	:client(client)
{
}

void RemoveDiscountCommand::execute()
{
	//client.getCart().removeDiscount(client.getPoints());
}
