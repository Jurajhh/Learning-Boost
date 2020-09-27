# Learning-Boost
Learning to use C++ Boost library

### Task 1:
Write a program that sends a std::vector (of say doubles) from a master C++ process to a child based on the BOOST ASIO C++ multi-threaded demo.

### Learning resources:

1. I went through some of the examples of Gamedev article:
https://www.gamedev.net/blogs/entry/2249317-a-guide-to-getting-started-with-boostasio/

2. and Bogotobogo tutorial sample for MULTITHREADING, SYNCHRONIZING, AND HANDLER with boost::asio: https://www.bogotobogo.com/cplusplus/Boost/boost_AsynchIO_asio_tcpip_socket_server_client_timer_bind_handler_multithreading_synchronizing_C.php

3. I tried to understand a Bogotobogo tutorial on TCP SOCKET PROGRAMMING that I believe would help me to solve the **_Task 1_** (see above):
https://www.bogotobogo.com/cplusplus/Boost/boost_AsynchIO_asio_tcpip_socket_server_client_timer_bind_handler_multithreading_synchronizing_network_D.php -- **_nevertheless, here, I came into an issue with ctime_** -- Error	C4996	'ctime': This function or variable may be unsafe. Consider using ctime_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS.
