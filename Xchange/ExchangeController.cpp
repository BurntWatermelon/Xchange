#include "ExchangeController.h"



//Listener should pick up calls from interface controller to add an exchange to the pool.
void ExchangeController::initializeListener()
{

}

//Static - thread unsafe
void ExchangeController::registerExchange(Exchange exch)
{

	ExchangeConnection newConnection();

	ExchangeController::exchange_connections.push_back(newConnection);
}

//Static
void ExchangeController::unregisterExchange()
{
	//	exchange_controller.add();
}