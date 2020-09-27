#include <iostream>
#include <boost/asio.hpp>

int main(int argc, char* argv[])
{
	boost::asio::io_service io_service;

	for (int x = 0; x < 42; ++x)
	{
		io_service.poll();
		// poll function:
		// runs the io_service object's event processing loop to execute ready handlers
		std::cout << "Counter: " << x << std::endl;
	}

	return 0;
}
