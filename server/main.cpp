#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sstream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <iostream>
#include "./dependencies/json.hpp"
#include <thread>
#include <map>
#include <vector>

#include "http_thread.cpp"
#include "udp_thread.cpp"


// This function creates a TCP Socket, accepts connections and sends
// responses to HTTP requests


int main()
{
    std::thread udp_thread(udp_server);
    std::thread http_thread(http_server);
    // In order to not exit the programm when Main finishes.
    // Here we could read user input.
    while (true)
    {
    }
    //udp_thread.join();
    //http_thread.join();
    return 0;
}
