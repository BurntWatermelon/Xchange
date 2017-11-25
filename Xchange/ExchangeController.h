#pragma once

#include <vector>
#include "ExchangeConnection.h"

//TODO make this a singleton - actually make it purely static object

class ExchangeController
{
public:
	void initializeListener();
	static void registerExchange();
	static void unregisterExchange();


	static std::vector<ExchangeConnection> exchange_connections;

private:
	ExchangeController() {}
	~ExchangeController() {}
};

