// Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <iostream>
#include "./dependencies/json.hpp"
#include <map>
#include <vector>

#define UDP_PORT 55443
#define MAXLINE 1024
using json = nlohmann::json;
using namespace std;

// Driver code
int main()
{
    int sockfd;
    char buffer[MAXLINE];
    char *hello = "Hello from server";
    struct sockaddr_in servaddr, cliaddr;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Filling server information
    servaddr.sin_family = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(UDP_PORT);

    // Bind the socket with the server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr,
             sizeof(servaddr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    int n;
    socklen_t len;
    len = sizeof(cliaddr); //len is value/result

    struct received_message {
        int timestamp;
        int value;
    };

    map<int, vector<received_message>> producer_data_map;
    map<int, vector<received_message>> consumer_data_map;
    map<int, vector<received_message>>* data_map_pointer;

    printf("Server is UP and running!");
    while (true)
    {

        // Wait for a message
        n = recvfrom(sockfd, (char *)buffer, MAXLINE,
                    MSG_WAITALL, (struct sockaddr *)&cliaddr,
                    &len);
        buffer[n] = '\0';

        printf("Client sent us: %s\n", buffer);
        auto json_data = json::parse(buffer);

        // Pointer points to correct vector
        if(json_data.at("type") == "c"){
            data_map_pointer = &consumer_data_map;
        } else {
            data_map_pointer = &producer_data_map;
        }

        received_message received_msg;
        received_msg.value = json_data.at("value");

        // Search if server doesn't know client
        if (data_map_pointer->find(json_data.at("id")) == data_map_pointer->end()) {
            // Save all into the dictionary
            data_map_pointer->insert(pair<int, vector<received_message>>(json_data.at("id"), vector<received_message>()));
            data_map_pointer->at(json_data.at("id")).push_back(received_msg);
        } else {
            // Save data on respective key
            data_map_pointer->at(json_data.at("id")).push_back(received_msg);
        }

        cout << "Data in map:   " << endl;
        for (auto const &pair : *data_map_pointer)
        {
            cout << "{" << pair.first << ": " << pair.second.back().value << "}\n";
        }

        /*
        sendto(sockfd, (const char *)hello, strlen(hello),
               MSG_CONFIRM, (const struct sockaddr *)&cliaddr,
               len);
        printf("Hello message sent.\n");
        */
    }
    return 0;
}
