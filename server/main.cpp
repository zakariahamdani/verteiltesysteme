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
// Sleep function
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "./messages.grpc.pb.h"
#include <grpcpp/grpcpp.h>

using grpc::Channel;
using grpc::ChannelCredentials;
using grpc::ClientContext;
using grpc::Status;

#include "http_thread.cpp"
#include "udp_thread.cpp"


class MessagesClient
{
public:
    MessagesClient(std::shared_ptr<Channel> channel)
        : stub_(messages::serverActions::NewStub(channel)) {}

    // Assembles the client's payload, sends it and presents the response back
    // from the server.
    bool turnOff()
    {
        // Data we are sending to the server.
        messages::Void request;

        // Container for the data we expect from the server.
        messages::Bool reply;

        // Context for the client. It could be used to convey extra information to
        // the server and/or tweak certain RPC behaviors.
        ClientContext context;

        // The actual RPC.
        std::cout << "CalledFunctionSTUB" << std::endl;
        Status status = stub_->turnOff(&context, request, &reply);

        // Act upon its status.
        if (status.ok())
        {
            return reply.boolvar();
        }
        else
        {
            std::cout << status.error_code() << ": " << status.error_message()
                      << std::endl;
            return "RPC failed";
        }
    }

private:
    std::unique_ptr<messages::serverActions::Stub> stub_;
};


// This function creates a TCP Socket, accepts connections and sends
// responses to HTTP requests
int main()
{
    std::thread udp_thread(udp_server);
    std::thread http_thread(http_server);

    std::cout << "Sleep started"<< std::endl;
    sleep(10);
    std::cout << "Sleep endet" <<std::endl;

    //gRPC
    std::string grpc_endpoint("172.20.0.3:50051");
    std::cout << "Using adress" << grpc_endpoint;

    std::shared_ptr<ChannelCredentials> channel_creds;
    channel_creds = grpc::InsecureChannelCredentials();

    MessagesClient messages_c(grpc::CreateChannel(grpc_endpoint, channel_creds));
    std::cout << "Created channel stub" << std::endl;
    messages_c.turnOff();
    std::cout << "Called function" << std::endl;

    // In order to not exit the programm when Main finishes.
    // Here we could read user input.
    while (true)
    {
        sleep(5);
        messages_c.turnOff();
    }
    //udp_thread.join();
    //http_thread.join();
    return 0;
}
