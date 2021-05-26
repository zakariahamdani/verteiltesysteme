//
// Created by zpraktikawm on 24.05.21.
//
#include "globalVariables.h"

int udpSockfd;
char udpBuffer[MAXLINE];
struct sockaddr_in servaddr, cliaddr;

int packetSize;
socklen_t sizeOfClientAdrr;

void setupUdpSocket();
void waitForPacket();
void parseAndSavePacket();

void udp_server()
{
    printf("Starting UDP-Server...");
    setupUdpSocket();

    printf("UDP-Server is UP and running!");
    while (true)
    {
        waitForPacket();
        parseAndSavePacket();
        /*
        sendto(sockfd, (const char *)hello, strlen(hello),
               MSG_CONFIRM, (const struct sockaddr *)&cliaddr,
               len);
        printf("Hello message sent.\n");
        */
    }
}

void setupUdpSocket(){

    // Creating socket file descriptor
    if ((udpSockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    //memset(&cliaddr, 0, sizeof(cliaddr));

    // Filling server information
    servaddr.sin_family = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(UDP_PORT);

    // Bind the socket with the server address
    if (bind(udpSockfd, (const struct sockaddr *)&servaddr,
             sizeof(servaddr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    sizeOfClientAdrr = sizeof(cliaddr); //len is value/result
}

void waitForPacket(){
    // Wait for a message
    packetSize = recvfrom(udpSockfd, (char *)udpBuffer, MAXLINE,
                          MSG_WAITALL,
                          (struct sockaddr *)&cliaddr,
                          &sizeOfClientAdrr);
    udpBuffer[packetSize] = '\0';
    printf("Client sent us: %s\n", udpBuffer);
}

void parseAndSavePacket(){

    auto json_data = nlohmann::json::parse(udpBuffer);

    // Pointer points to corresponding vector
    if (json_data.at("type") == "c")
    {
        data_map_pointer = &consumer_data_map;
    }
    else
    {
        data_map_pointer = &producer_data_map;
    }

    //parsing
    received_message received_msg;
    received_msg.value = json_data.at("value");
    received_msg.timestamp = json_data.at("timeStamp");
    received_msg.id = json_data.at("id");

    // Search if server doesn't know client
    if (data_map_pointer->find(json_data.at("id")) == data_map_pointer->end())
    {
        // insert a new element if it's the first time to receive from this client
        data_map_pointer->insert(std::pair<int, std::vector<received_message>>(json_data.at("id"), std::vector<received_message>()));
        //and then pushback the received msg
        data_map_pointer->at(json_data.at("id")).push_back(received_msg);
    }
    else
    {
        // Save data on respective key
        data_map_pointer->at(json_data.at("id")).push_back(received_msg);
    }
}