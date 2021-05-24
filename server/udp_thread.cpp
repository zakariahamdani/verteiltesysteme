//
// Created by zpraktikawm on 24.05.21.
//
#include "globalVariables.h"
void udp_server()
{
    printf("Starting UDP-Server...");

    int sockfd;
    char buffer[MAXLINE];
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

    printf("UDP-Server is UP and running!");
    while (true)
    {

        // Wait for a message
        n = recvfrom(sockfd, (char *)buffer, MAXLINE,
                     MSG_WAITALL, (struct sockaddr *)&cliaddr,
                     &len);
        buffer[n] = '\0';

        printf("Client sent us: %s\n", buffer);
        auto json_data = nlohmann::json::parse(buffer);

        // Pointer points to correct vector
        if (json_data.at("type") == "c")
        {
            data_map_pointer = &consumer_data_map;
        }
        else
        {
            data_map_pointer = &producer_data_map;
        }

        received_message received_msg;
        received_msg.value = json_data.at("value");
        received_msg.timestamp = json_data.at("timeStamp");
        received_msg.id = json_data.at("id");

        // Search if server doesn't know client
        if (data_map_pointer->find(json_data.at("id")) == data_map_pointer->end())
        {
            // Save all into the dictionary
            data_map_pointer->insert(std::pair<int, std::vector<received_message>>(json_data.at("id"), std::vector<received_message>()));
            data_map_pointer->at(json_data.at("id")).push_back(received_msg);
        }
        else
        {
            // Save data on respective key
            data_map_pointer->at(json_data.at("id")).push_back(received_msg);
        }

        std::cout << "Data in map:\n"
                  << std::endl;
        for (auto const &pair : *data_map_pointer)
        {
            std::cout << pair.second.size() << " elements in id " << pair.first << ". Last element: {"
                      << pair.first << ": " << pair.second.back().value << "}\n";
        }

        /*
        sendto(sockfd, (const char *)hello, strlen(hello),
               MSG_CONFIRM, (const struct sockaddr *)&cliaddr,
               len);
        printf("Hello message sent.\n");
        */
    }
}
