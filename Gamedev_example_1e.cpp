#include <iostream>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>

int main(int argc, char* argv[])
{
	boost::asio::io_service io_service;
	boost::shared_ptr< boost::asio::io_service::work > work1(
		new boost::asio::io_service::work(io_service)
	);

	work1.reset();

	io_service.run();

	std::cout << "Does display? (E 1e)" << std::endl;

	return 0;
}
