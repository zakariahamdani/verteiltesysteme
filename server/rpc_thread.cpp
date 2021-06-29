// Client side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <time.h>
#include <iostream>
#include "./messages.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include "./globalVariables.h"

#define UDP_PORT 55443
#define MAXLINE 1024

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
// The gRPC server is defined globally so that SIGTERM handler can shut it down
std::unique_ptr<Server> server;

// Logic and data behind the server's behavior.
class serverQueriesServiceImpl final : public messages::serverQueries::Service
{
    grpc::Status getHistoryOfAllParticipants(ServerContext *context, const messages::Void *request,
                                             messages::entireHistory *reply) override
    {
        // consumer_data_map type: std::map<int, std::vector<received_message>>
        for (auto &consumer : consumer_data_map) {
            // Constructure structure from here: https://stackoverflow.com/questions/33960999/protobuf-will-set-allocated-delete-the-allocated-object
            messages::participant *participant = new messages::participant();
            participant->set_type("c");
            participant->set_id(consumer.second.at(0).id); //.second contains the vector

            // add_ behaviour: 
            //  https://developers.google.com/protocol-buffers/docs/reference/cpp-generated#:~:text=behavior.-,Bar*%20add_foo(),-%3A%20Adds
            messages::participantHistory *pHistory = reply->add_participanthistory();

            // set_allocated behaviour: 
            //  https://developers.google.com/protocol-buffers/docs/reference/cpp-generated#:~:text=void-,set_allocated_foo,-(Bar*%20bar)%3A%20Sets
            pHistory->set_allocated_participant(participant);

            // received_message structure:
            //   struct received_message {
            //       long int timestamp;
            //       int value;
            //       int id; };
            for (auto &consumer_history : consumer.second) {
                messages::participantInformation *pInformation = pHistory->add_participantinformation();
                pInformation->set_value(consumer_history.value);
                pInformation->set_timestamp(consumer_history.timestamp);
            }
        }
        
        // Same as ⤴, but now with the producer's map
        for (auto &producer : producer_data_map) {
            messages::participant *participant = new messages::participant();
            participant->set_type("p");
            participant->set_id(producer.second.at(0).id); 
            messages::participantHistory *pHistory = reply->add_participanthistory();
            pHistory->set_allocated_participant(participant);
            for (auto &producer_history : producer.second) {
                messages::participantInformation *pInformation = pHistory->add_participantinformation();
                pInformation->set_value(producer_history.value);
                pInformation->set_timestamp(producer_history.timestamp);
            }
        }
        return Status::OK;
    }
};

void run_gRPC()
{
    std::cout << "Running RPC " << std::endl;
    std::string server_address("0.0.0.0:50051");
    serverQueriesServiceImpl service;
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
    printf("Server listening on %s\n", server_address);

    // Wait for the server to shutdown.
    server->Wait();
}
