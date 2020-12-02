#include <iostream>
#include <tcp/tcp_server.hpp>
#include <sstream>

using std::string;
using std::cout;

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <stdio.h>
#include <unistd.h>
#include <string.h> /* For strncpy */
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>

#include <cstring>
#include <iostream>

void print(Node *nd, string msg)
{
  cout<< nd->ip <<" : " << msg << std::endl;
}

int main(int argc, char** argv)
{
  //initialize default port number and max connection cout
  int port;

  // check if there are any passed arguments
  if(argc > 1)
  {
    // initialize string stream from argument
    std::istringstream arg_stream(argv[1]);

    // bind arguments stream to port int variable if valid
    if ( !(arg_stream >> port) )
    {
        std::cerr << "Invalid number " << argv[1] << std::endl;
    }
  } else {
    cout << "Usage: server <port>" << std::endl;
    return 0;
  }

  // create server instance with specified port number
  tcp::server server(port);

  // set async fn to handle incoming messages
  server.OnMessage(print);

  //start listening to connections
  int result = server.Listen();

  if(result != 0)
    cout << "Failed to start server !" << std::endl;

  return 0;
}