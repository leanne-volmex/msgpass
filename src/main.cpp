#include "../include/msg.hpp"
#include<iostream>
int main()
{
    json data = {{"name", "json"}, {"age", 101}};
    vector<unsigned char> message = pack_outgoing_message_to_nest("some_pattern", data);
    for(const auto c: message){
        std::cout << c;
    }
}