// https://www.bogotobogo.com/cplusplus/Boost/boost_AsynchIO_asio_tcpip_socket_server_client_timer_bind_handler_multithreading_synchronizing_C.php
// I modified the code from Bogotobogo slightly to fix minor issues.


#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

class handler
{
public:
    handler(boost::asio::io_service& io)
        : m_strand(io),
        m_timer1(io, boost::posix_time::seconds(1)),
        m_timer2(io, boost::posix_time::seconds(1)),
        m_count(0)
    {
        m_timer1.async_wait(m_strand.wrap(boost::bind(&handler::message1, this)));
        m_timer2.async_wait(m_strand.wrap(boost::bind(&handler::message2, this)));
    }

    ~handler()
    {
        std::cout << "the last count : " << m_count << "\n";
    }

    void message1()
    {
        if (m_count < 10)
        {
            std::cout << "timer 1: " << m_count << "\n";
            ++m_count;

            m_timer1.expires_at(m_timer1.expires_at() + boost::posix_time::seconds(1));
            m_timer1.async_wait(m_strand.wrap(boost::bind(&handler::message1, this)));
        }
    }

    void message2()
    {
        if (m_count < 10)
        {
            std::cout << "timer 2: " << m_count << "\n";
            ++m_count;

            m_timer2.expires_at(m_timer2.expires_at() + boost::posix_time::seconds(1));
            m_timer2.async_wait(m_strand.wrap(boost::bind(&handler::message2, this)));
        }
    }

private:
    boost::asio::io_service::strand m_strand;
    boost::asio::deadline_timer m_timer1;
    boost::asio::deadline_timer m_timer2;
    int m_count;
};

int main()
{
    boost::asio::io_service io;
    handler h(io);
    boost::thread t(boost::bind(&boost::asio::io_service::run, &io));
    io.run();
    t.join();

    return 0;
}
