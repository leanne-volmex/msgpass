#pragma once

#include<cstring>
#include<unordered_map>
#include<string>
#include <boost/uuid/uuid.hpp>  
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>
#include <sstream>

#include <sys/socket.h> // for the socket functions
#include <netinet/in.h> // for the sockaddr_in structure
#include <arpa/inet.h> // for the inet_ntoa function
#include <unistd.h> // for the close function
//#include "../lib/nlohmann/json.hpp"
#include <nlohmann/json.hpp>




using std::string;
using std::to_string;
using std::vector;
using nlohmann::json;

vector<unsigned char> pack_outgoing_message_to_nest(const string& pattern, const nlohmann::json& data)
{
    boost::uuids::random_generator generator;

    boost::uuids::uuid _id = generator();

    json dict_merged = {
        {"pattern", pattern},
        {"data", data},
        {"id", boost::uuids::to_string(_id)}
    };
    string s_json = dict_merged.dump();
    vector<unsigned char> message;
    message.reserve(s_json.length()+1);
    message.insert(message.end(), s_json.begin(), s_json.end());
    message.push_back('#');
    return message;
}

