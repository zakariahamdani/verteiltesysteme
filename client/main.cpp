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
#include "./dependencies/json.hpp"
#include "./dependencies/cxxopts.hpp"

#define UDP_PORT 55443
#define MAXLINE 1024

int initialize_udp_client();
struct sockaddr_in fillServerInformation();
nlohmann::json writeParsedCommandLineOptions(int p_argc, char **p_argv);
std::time_t getTimeStamp();

int main(int argc, char **argv)
{
    struct sockaddr_in servaddr = fillServerInformation();
    int client_socket = initialize_udp_client();
    nlohmann::json client_data = writeParsedCommandLineOptions(argc, argv);

    srand(client_data["id"]);

    while (true)
    {
        // Create data to send
        int value = rand()%1000;
        client_data["value"] = value;
        client_data["timeStamp"] = getTimeStamp();
        // Serialize the structure to a json-string
        char serialized[client_data.dump().length()]; // Create a char[] big enough to hold our serialized str
        strcpy(serialized, client_data.dump().c_str()); // Save the serialized str on that created variable

        sendto(client_socket, serialized, strlen(serialized),
               MSG_CONFIRM, (const struct sockaddr *)&servaddr,
               sizeof(servaddr));
        printf("Message sent:");
        printf(serialized, "\n");

        sleep(2);
    }
    close(client_socket);
    return 0;
}

int initialize_udp_client(){
    int client_socket;

    // Creating socket file descriptor
    if ((client_socket = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    return client_socket;
}

struct sockaddr_in fillServerInformation(){
    // Filling server information
    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(UDP_PORT);
    servaddr.sin_addr.s_addr = inet_addr("172.20.0.2"); // Docker-server Static IP
    //servaddr.sin_addr.s_addr = INADDR_ANY; // Local (Use it when not using the docker network)

    return servaddr;
}

nlohmann::json writeParsedCommandLineOptions(int p_argc, char **p_argv){
    nlohmann::json client_data;

    cxxopts::Options options("main", "A client that can be either consumer or producer");
    options.add_options()
            ("c,consumer", "Makes the client a consumer. If it isn't set, the Client will be a Producer", cxxopts::value<bool>()->default_value("false"))
            ("i,id", "Client's ID", cxxopts::value<int>())
            ("h,help", "Print help");

    cxxopts::ParseResult result = options.parse(p_argc, p_argv);

    if (result.count("help")){
        std::cout << options.help() << std::endl;
        exit(0);
    }
    // Write readed data
    if (result.count("consumer")){
        client_data["type"] = "c";
    }else{
        client_data["type"] = "p";
    }

    // Catch if user didn't passed any parameters
    try {
        client_data["id"] = result["id"].as<int>();
    } catch (cxxopts::option_has_no_value_exception) {
        std::cout << options.help() << std::endl;
        exit(0);
    }
    return client_data;
}

long int getTimeStamp()
{
    return static_cast<long int>(std::time(nullptr));
}