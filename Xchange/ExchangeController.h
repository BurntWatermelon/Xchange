#pragma once

#include <vector>
#include "ExchangeConnection.h"

//TODO make this a singleton - actually make it purely static object

enum Exchange { bittrex, bitfinex };

class ExchangeController
{
public:
	void initializeListener();
	static void registerExchange(Exchange exchange);
	static void unregisterExchange();


	static std::vector<ExchangeConnection> exchange_connections;

private:
	ExchangeController() {}
	~ExchangeController() {}
};




