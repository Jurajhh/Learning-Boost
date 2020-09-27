#include <iostream>
#include <boost/asio.hpp>

int main(int argc, char* argv[])
{
    boost::asio::io_service io_service;

    io_service.run();

    std::cout << "Do you reckon this line displays?" << std::endl;

    return 0;
}
