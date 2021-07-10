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
#include "./rpc_thread.cpp"

using grpc::Channel;
using grpc::ChannelCredentials;
using grpc::ClientContext;
using grpc::Status;

#include "http_thread.cpp"
#include "udp_thread.cpp"
#include "mqtt_thread.cpp"


class MessagesClient {
public:
    MessagesClient(std::shared_ptr<Channel> channel)
        : stub_(messages::serverActions::NewStub(channel)) {}

    // Assembles the client's payload, sends it and presents the response back
    // from the server.
    bool turnOff() {
        // Data we are sending to the server.
        messages::Void request;

        // Container for the data we expect from the server.
        messages::Bool reply;

        // Context for the client. It could be used to convey extra information to
        // the server and/or tweak certain RPC behaviors.
        ClientContext context;

        // The actual RPC.
        // std::cout << "Sending turn Off request" << std::endl;
        Status status = stub_->turnOff(&context, request, &reply);

        // Act upon its status.
        if (status.ok())
        {
            return reply.boolvar();
        } else {
            std::cout << status.error_code() << ": " << status.error_message()
                      << std::endl;
            return "RPC failed";
        }
    }

    bool turnOn() {
        // Data we are sending to the server.
        messages::Void request;

        // Container for the data we expect from the server.
        messages::Bool reply;

        // Context for the client. It could be used to convey extra information to
        // the server and/or tweak certain RPC behaviors.
        ClientContext context;

        // The actual RPC.
        //std::cout << "Sending turn On request" << std::endl;
        Status status = stub_->turnOn(&context, request, &reply);

        // Act upon its status.
        if (status.ok()) {
            return reply.boolvar();
        } else {
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
int main() {
    //std::thread udp_thread(udp_server);
    std::thread http_thread(http_server);
    std::thread rpc_thread(run_gRPC);
    std::thread mqtt_thread(run_mqtt);

    std::cout
        << "Waiting for gRPC server..." << std::endl;
    sleep(5);

    //gRPC
    std::string grpc_endpoint_c1("172.20.0.3:50051"); // Consumer 1
    std::string grpc_endpoint_c3("172.20.0.4:50051");
    std::string grpc_endpoint_c5("172.20.0.5:50051");
    std::string grpc_endpoint_p2("172.20.0.6:50051"); // Producer 2

    MessagesClient messages_c1(grpc::CreateChannel(grpc_endpoint_c1, grpc::InsecureChannelCredentials()));
    MessagesClient messages_c3(grpc::CreateChannel(grpc_endpoint_c3, grpc::InsecureChannelCredentials()));
    MessagesClient messages_c5(grpc::CreateChannel(grpc_endpoint_c5, grpc::InsecureChannelCredentials()));
    MessagesClient messages_p2(grpc::CreateChannel(grpc_endpoint_p2, grpc::InsecureChannelCredentials()));

    // In order to not exit the programm when Main finishes.
    // Here we could read user input.
    while (true) {
        std::cout << "Turning off all clients" << std::endl;
        messages_c1.turnOff();
        messages_c3.turnOff();
        messages_c5.turnOff();
        messages_p2.turnOff();
        sleep(5);
        std::cout << "Turning on all clients" << std::endl;
        messages_c1.turnOn();
        messages_c3.turnOn();
        messages_c5.turnOn();
        messages_p2.turnOn();
        sleep(5);
    }
    //udp_thread.join();
    //http_thread.join();
    return 0;
}
