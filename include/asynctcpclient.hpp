#pragma once

#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/read_until.hpp>
#include <string>
#include <iostream>

using namespace boost::asio;
using namespace boost::asio::ip;

class TcpClient {
 public:
  TcpClient(io_context& io_context) : socket_(io_context) {}

  void Connect(const std::string& host, const std::string& port) {
    tcp::resolver resolver(socket_.get_io_context());
    boost::asio::connect(socket_, resolver.resolve(host, port));
  }

  void Write(const std::string& message) {
    boost::asio::write(socket_, buffer(message));
  }

  std::string ReadUntil(const std::string& delimiter) {
    boost::asio::streambuf buffer;
    boost::asio::read_until(socket_, buffer, delimiter);
    std::string message = buffer_cast<const char*>(buffer.data());
    return message;
  }

 private:
  tcp::socket socket_;
};

