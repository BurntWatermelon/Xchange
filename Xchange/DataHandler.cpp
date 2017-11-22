#include "DataHandler.h"

#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <windows.h>

using namespace utility;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;

//Api communication handled by Microsoft's cpprestsdk

DataHandler::DataHandler()
{
}


DataHandler::~DataHandler()
{
}

//CPPRESTSDK TEST
web::http::client::http_client_config client_config_for_proxy()
{
	web::http::client::http_client_config client_config;
#ifdef _WIN32
	wchar_t* pValue = nullptr;
	std::unique_ptr<wchar_t, void(*)(wchar_t*)> holder(nullptr, [](wchar_t* p) { free(p); });
	size_t len = 0;
	auto err = _wdupenv_s(&pValue, &len, L"http_proxy");
	if (pValue)
		holder.reset(pValue);
	if (!err && pValue && len) {
		std::wstring env_http_proxy_string(pValue, len - 1);
#else
	if (const char* env_http_proxy = std::getenv("http_proxy")) {
		std::string env_http_proxy_string(env_http_proxy);
#endif
		if (env_http_proxy_string == U("auto"))
			client_config.set_proxy(web::web_proxy::use_auto_discovery);
		else
			client_config.set_proxy(web::web_proxy(env_http_proxy_string));
	}

	return client_config;
}

//entry point to data listener thread. Manages each exchange connection object 
void DataHandler::run()
{
	while (true);
	Sleep(1000);

	//use the singleton browserview get instance to get the handle on it.



	//Test CPPRESTSDK 
	
	if (argc != 3)
	{
		printf("Usage: BingRequest.exe search_term output_file\n");
		return -1;
	}
	const string_t searchTerm = args[1];
	const string_t outputFileName = args[2];

	// Open a stream to the file to write the HTTP response body into.
	auto fileBuffer = std::make_shared<streambuf<uint8_t>>();
	file_buffer<uint8_t>::open(outputFileName, std::ios::out).then([=](streambuf<uint8_t> outFile) -> pplx::task<http_response>
	{
		*fileBuffer = outFile;

		// Create an HTTP request.
		// Encode the URI query since it could contain special characters like spaces.
		http_client client(U("http://www.bing.com/"), client_config_for_proxy());
		return client.request(methods::GET, uri_builder(U("/search")).append_query(U("q"), searchTerm).to_string());
	})

		// Write the response body into the file buffer.
		.then([=](http_response response) -> pplx::task<size_t>
	{
		printf("Response status code %u returned.\n", response.status_code());

		return response.body().read_to_end(*fileBuffer);
	})

		// Close the file buffer.
		.then([=](size_t)
	{
		return fileBuffer->close();
	})

		// Wait for the entire response body to be written into the file.
		.wait();

	return 0;
	
}

