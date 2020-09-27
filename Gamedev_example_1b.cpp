#include <iostream>
#include <boost/asio.hpp>

int main(int argc, char* argv[])
{
	boost::asio::io_service io_service;
	boost::asio::io_service::work work(io_service);

	//io_service.run();
	io_service.poll();

	std::cout << "Do you reckon this this this line displays?" << std::endl;

	return 0;
}
