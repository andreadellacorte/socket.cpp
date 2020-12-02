#include <iostream>
#include <tcp/tcp_client.hpp>
#include <sstream>
#include <string>

using std::string;

#define DEFAULT_MESSAGE "Hi! - from client"

int main(int argc, char** argv)
{

  // initialize default port number and max connection cout
  int     port;
  string  address;

  // check if there are any passed arguments
  if(argc == 3)
  {
    // bind arguments stream to address int variable if valid
    address = argv[1];

    port = std::stoi(argv[2]);
  } else {
    cout << "Usage: client <address> <port>\n";
    return 0;
  }

  // create server instance with specified port number
  tcp::client client(address,port);

  // connect to host node
  client.Connect();

  // send message to host
  client.Send(DEFAULT_MESSAGE);

  // send message to host
  client.Stop();

  return 0;
}