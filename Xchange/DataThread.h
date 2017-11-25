#pragma once
class DataThread
{
public:
	DataThread();
	~DataThread();
	void run();

	void initializeListener();

	void registerExchange();

private:
//	ExchangeController exchange_controller();
	//InterfaceController interface_controller();
};

