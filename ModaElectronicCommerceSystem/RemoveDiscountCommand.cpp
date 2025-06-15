#include "RemoveDiscountCommand.h"

RemoveDiscountCommand::RemoveDiscountCommand(Client& client)
	:client(client)
{
}

void RemoveDiscountCommand::execute(System& system)
{
	//client.getCart().removeDiscount(client.getPoints());
}
