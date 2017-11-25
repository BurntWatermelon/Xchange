#include "ExchangeController.h"



ExchangeController::ExchangeController()
{
}


ExchangeController::~ExchangeController()
{
}

//Listener should pick up calls from interface controller to add an exchange to the pool.
void ExchangeController::initializeListener()
{

}

// this doesnt need to be in here, its not thread specific, data thread should just be for pulling data. you can register a new connection here though
void ExchangeController::registerExchange()
{
	//	exchange_controller.add();
}
