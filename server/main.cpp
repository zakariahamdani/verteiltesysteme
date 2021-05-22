// Server side implementation of UDP client-server model
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

#define UDP_PORT 55443
#define HTTP_PORT 8001
#define MAXLINE 1024
using json = nlohmann::json;
using namespace std;

// TODO: Create a header and put all this in there
struct received_message
{
    int timestamp;
    int value;
};
map<int, vector<received_message>> producer_data_map;
map<int, vector<received_message>> consumer_data_map;
map<int, vector<received_message>> *data_map_pointer;

void http_server(){
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8001
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(HTTP_PORT);

    // Forcefully attaching socket to the port 8001
    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    while (true){
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                             (socklen_t *)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Get client (browser) request data
    valread = read(new_socket, buffer, 1024);
    printf("%s\n", buffer);

    bool send_404 = false;
    std::string content;
    stringstream http_header;
    http_header << buffer;
    string http_header_word;
    getline(http_header, http_header_word, ' ');
    if (http_header_word == "GET"){
        getline(http_header, http_header_word, ' ');
        http_header.str(http_header_word); // Save URL of requeste resource
        printf("This should be the URL: %s", http_header_word.c_str());
        getline(http_header, http_header_word, '/'); // Ignore first slash 
        getline(http_header, http_header_word, '/');

        // We accept URLs with this structure:
        //  /api/[consumer,producer]/[id]
        if (http_header_word == "api"){
            getline(http_header, http_header_word, '/');
            if (http_header_word == "consumer") {
                getline(http_header, http_header_word, '/');
                // Convert ID to integer and see if we have it on list
                try {
                    if (consumer_data_map.find(stoi(http_header_word)) == consumer_data_map.end()) {
                        send_404 = true;
                        printf("ID %s wasn't found/wasn't a number", http_header_word.c_str());
                    }
                    else {
                        content.append("<h1>ID:" + http_header_word + "</h1>\n");
                        for (auto const &pair : *data_map_pointer) {
                            for (auto &sec_pair: pair.second){
                                content.append("<h2> Timestamp:" + to_string(sec_pair.timestamp) + " Value:"+to_string(sec_pair.value) + "</h2>\n");
                            }
                        }
                    }
                }
                catch (exception &err) {
                    cout << "Conversion failure: " << err.what() << endl; // Note: what() tells the exact error
                }
            }
            else if (http_header_word == "producer") {
                getline(http_header, http_header_word, '/');
                // Convert ID to integer and see if we have it on list
                try{
                    if (producer_data_map.find(stoi(http_header_word)) == producer_data_map.end()) {
                        send_404 = true;
                        printf("ID %s wasn't found/wasn't a number", http_header_word.c_str());
                    }
                    else {
                        content.append("<h1>ID:" + http_header_word + "</h1>\n");
                        for (auto const &pair : *data_map_pointer) {
                            for (auto &sec_pair : pair.second) {
                                content.append("<h2> Timestamp:" + to_string(sec_pair.timestamp) + " Value:" + to_string(sec_pair.value) + "</h2>\n");
                            }
                        }
                    }
                }
                catch (exception &err)
                {
                    cout << "Conversion failure: " << err.what() << endl; // Note: what() tells the exact error
                }
            } else {
                printf("It was %s and not consumer/producer", http_header_word.c_str());
            }
        } else {
            printf("It was %s and not api", http_header_word.c_str());
        }
    } else {
        // Else show a 404 page, or something as default
        printf("Rejected! With: %s", http_header_word.c_str());
    }

    // Write the document back to the client

    std::ostringstream oss;
    oss << "HTTP/1.1 200 OK\r\n";
    oss << "Cache-Control: no-cache, private\r\n";
    oss << "Content-Type: text/html\r\n";
    oss << "Content-Length: " << content.size() << "\r\n\r\n";
    oss << content;

    std::string output = oss.str();
    int size = output.size() + 1;

    send(new_socket, output.c_str(), size,0);

    //send(new_socket, hello, strlen(hello), 0);
    printf("Hello message sent\n");
    }
}

void udp_server(){
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
        auto json_data = json::parse(buffer);

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

        // Search if server doesn't know client
        if (data_map_pointer->find(json_data.at("id")) == data_map_pointer->end())
        {
            // Save all into the dictionary
            data_map_pointer->insert(pair<int, vector<received_message>>(json_data.at("id"), vector<received_message>()));
            data_map_pointer->at(json_data.at("id")).push_back(received_msg);
        }
        else
        {
            // Save data on respective key
            data_map_pointer->at(json_data.at("id")).push_back(received_msg);
        }

        cout << "Data in map:\n" << endl;
        for (auto const &pair : *data_map_pointer)
        {
            cout << pair.second.size() << " elements in id " << pair.first << ". Last element: {"
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

int main(){
        std::thread udp_thread(udp_server);
        std::thread http_thread(http_server);
        // In order to not exit the programm when Main finishes.
        // Here we could read user input.
        while(true){
            
        }
        //udp_thread.join();
        //http_thread.join();
    return 0;
}