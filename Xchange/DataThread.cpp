#include "DataThread.h"

#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <windows.h>

#include "cef_browser_hook.h"

using namespace utility;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;

//Api communication handled by Microsoft's cpprestsdk

DataThread::DataThread()
{
}


DataThread::~DataThread()
{
}


//entry point to data listener thread. Manages each exchange connection object 
void DataThread::run()
{
	//use the singleton browserview get instance to get the handle on it.

	CefBrowserHook* browserInstance = CefBrowserHook::GetInstance();
	browserInstance->CloseAllBrowsers(true);

	//Get a handle on the exchange manager and just loop through each connection, the mutex should be on the exchange controllers's objects


	//Test CPPRESTSDK 
	


		// Create an HTTP request.
		// Encode the URI query since it could contain special characters like spaces.
		http_client client(U("http://www.bing.com/"));
		Concurrency::task<http_response> response = client.request(methods::GET, uri_builder(U("/search")).append_query(U("q"), "league").to_string());
		MessageBox(
			NULL,
			response.get().extract_string().get().c_str(),
			(LPCWSTR)L"Account Details",
			MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
		); 
		
}


