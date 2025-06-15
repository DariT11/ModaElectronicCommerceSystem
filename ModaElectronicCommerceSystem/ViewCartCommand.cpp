#include "ViewCartCommand.h"

ViewCartCommand::ViewCartCommand(Client& client)
	:client(client)
{

}

void ViewCartCommand::execute(System& system)
{
	client.getCart().view();
}
