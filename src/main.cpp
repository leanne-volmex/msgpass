#include "../include/msg.hpp"
#include<boost/asio.hpp>
#include<fmt/core.h>

#include "../include/server.h"

#include<iostream>
int main()
{
    fmt::print("This is a async tcp client yet to be done!\n");
    json data = {{"name", "json"}, {"age", 101}};
    vector<unsigned char> message = pack_outgoing_message_to_nest("some_pattern", data);
    for(const auto c: message){
        std::cout << c;
    }
    std::cout << std::endl;

    try {
    // Create a TCP socket
        boost::asio::io_context io_context;
        boost::asio::ip::tcp::socket socket(io_context);

        // Connect to the server
        boost::asio::ip::tcp::resolver resolver(io_context);
        boost::asio::connect(socket, resolver.resolve("localhost", "8000"));

        // Send a request to the server
        std::string request = "GET / HTTP/1.1\r\n\r\n";
        boost::asio::write(socket, boost::asio::buffer(request));

        // Read the response from the server
        boost::asio::streambuf response;
        boost::asio::read_until(socket, response, "\r\n");

        // Print the response to the console
        std::cout << &response;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }


    boost::asio::io_context io_context;
    server srv(io_context, 15001);
    srv.async_accept();
    io_context.run();



    return 0;
}