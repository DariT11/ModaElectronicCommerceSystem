#include "ViewCartCommand.h"

ViewCartCommand::ViewCartCommand(Client& client)
	:client(client)
{

}

void ViewCartCommand::execute()
{
	client.getCart().view();
}
