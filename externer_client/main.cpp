#include "./messages.grpc.pb.h"
#include <grpcpp/grpcpp.h>
// Sleep function
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using grpc::Channel;
using grpc::ChannelCredentials;
using grpc::ClientContext;
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

class MessagesClient {
public:
    MessagesClient(std::shared_ptr<Channel> channel)
        : stub_(messages::serverQueries::NewStub(channel)) {}

    // Assembles the client's payload, sends it and presents the response back
    // from the server.
    messages::entireHistory getHistoryOfAllParticipants() {
        // Data we are sending to the server.
        messages::Void request;

        // Container for the data we expect from the server.
        messages::entireHistory reply;

        // Context for the client. It could be used to convey extra information to
        // the server and/or tweak certain RPC behaviors.
        ClientContext context;

        // The actual RPC.
        // std::cout << "Sending turn Off request" << std::endl;
        Status status = stub_->getHistoryOfAllParticipants(&context, request, &reply);

        // Act upon its status.
        if (status.ok()) {
        } else {
            std::cout << status.error_code() << ": " << status.error_message()
                      << std::endl;
        }
        return reply;
    }

private:
    std::unique_ptr<messages::serverQueries::Stub> stub_;
};


int main(int argc, char **argv) {
    std::cout << "Welcome to our extern client" << std::endl;
    //gRPC
    std::string grpc_endpoint("172.20.0.2:50051"); // Server
    MessagesClient messages(grpc::CreateChannel(grpc_endpoint, grpc::InsecureChannelCredentials()));

    while(true) {
        std::cout << "Press enter to get the historical data of every client connected to the server" << std::endl;
        std::cin.ignore();
        messages::entireHistory eHistory = messages.getHistoryOfAllParticipants();
        for (auto &participant_data : *eHistory.mutable_participanthistory()) {
            messages::participant participant = participant_data.participant();
            std::cout << "\nTYPE: " << participant.type() << "\t\tID: " << participant.id() << std::endl;
            int counter = 0;
            for (auto &participant_history : *participant_data.mutable_participantinformation()) {
                std::cout << "timestamp: " << participant_history.timestamp() 
                        << " value: "      << participant_history.value()<<"  \t";
                if(++counter%3==0){
                    std::cout << std::endl;
                }
            }
        }
        std::cout << "\n\n";
    }
}
