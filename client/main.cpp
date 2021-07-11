// Client side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <iostream>
#include <time.h>
#include <csignal>
#include <future>
#include <iostream>
#include <thread>
#include "./dependencies/json.hpp"
#include "./dependencies/cxxopts.hpp"
#include "./messages.grpc.pb.h"
#include "./mqtt_thread.cpp"
#include <grpcpp/grpcpp.h>
#include "globalVariables.h"

#define UDP_PORT 55443
#define MAXLINE 1024

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

// If false, this participant will stop generating and sending new messages
bool isOn = true;

// The gRPC server is defined globally so that SIGTERM handler can shut it down
std::unique_ptr<Server> server;

// Logic and data behind the server's behavior.
class serverActionsServiceImpl final : public messages::serverActions::Service {
    grpc::Status turnOff(ServerContext *context, const messages::Void *request,
                         messages::Bool *reply) override {
        //std::cout << "Turning off this client..." << std::endl;
        CLIENT_RUNNING = false;
        reply->set_boolvar(true);
        return Status::OK;
    }

    grpc::Status turnOn(ServerContext *context, const messages::Void *request,
                        messages::Bool *reply) override {
        //std::cout << "Turning on this client..." << std::endl;
        CLIENT_RUNNING = true;
        reply->set_boolvar(true);
        return Status::OK;
    }
};

void run_gRPC() {
    std::cout << "Running RPC " << std::endl;
    std::string server_address("0.0.0.0:50051");
    serverActionsServiceImpl service;  
    ServerBuilder builder;

    // Listen on the given address without any authentication mechanism. 
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    std::cout << "Port registered on: " << server_address << std::endl;

    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to a *synchronous* service.
    builder.RegisterService(&service);
    printf("Service registered\n");

    // Finally assemble the server.
    server = builder.BuildAndStart();
    printf("Server listening on %s\n" , server_address);

    std::signal(SIGTERM, [](int)
        {
            // When SIGTERM is received, shutdown the gRPC server.
            server->Shutdown();
        });

    // Wait for the server to shutdown.
    server->Wait();
}

nlohmann::json writeParsedCommandLineOptions(int p_argc, char **p_argv);
std::time_t getTimeStamp();

int main(int argc, char **argv) {
    client_data = writeParsedCommandLineOptions(argc, argv);
    std::cout << "Time to run gRPC...";
    std::thread t_run_mqttClient(run_mqtt, client_data["id"]);
    std::thread t_run_gRPC(&run_gRPC);

    srand(client_data["id"]);
    std::cout << "Client with ID:" << client_data["id"] << std::endl;

    t_run_mqttClient.join();
    return 0;
}

nlohmann::json writeParsedCommandLineOptions(int p_argc, char **p_argv) {
    cxxopts::Options options("main", "A client that can be either consumer or producer");
    options.add_options()
            ("c,consumer", "Makes the client a consumer. If it isn't set, the Client will be a Producer", cxxopts::value<bool>()->default_value("false"))
            ("i,id", "Client's ID", cxxopts::value<int>())
            ("h,help", "Print help");

    cxxopts::ParseResult result = options.parse(p_argc, p_argv);

    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        exit(0);
    }
    // Write readed data
    if (result.count("consumer")) {
        client_data["type"] = "c";
    } else {
        client_data["type"] = "p";
    }

    // Catch if user didn't passed any parameters
    try {
        client_data["id"] = result["id"].as<int>();
       // CLIENT_ID = client_data["id"];
    }
    catch (cxxopts::option_has_no_value_exception) {
        std::cout << options.help() << std::endl;
        exit(0);
    }
    return client_data;
}