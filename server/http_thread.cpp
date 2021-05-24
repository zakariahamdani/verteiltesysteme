//
// Created by zpraktikawm on 24.05.21.
//
#include "globalVariables.h"


void http_server()
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};


    // Create socket and attach it to the HTTP_PORT
    // Programm closes if we can't create-connect our socket to a port
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Accept connections from any IP
    address.sin_port = htons(HTTP_PORT);
    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Here we wait for a connection to our socket and send a response to a HTTP request
    while (true)
    {
        if (listen(server_fd, 3) < 0)
        {
            perror("listen");
            exit(EXIT_FAILURE);
        }
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                 (socklen_t *)&addrlen)) < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        // At this point we already made a TCP connection with (probably) a browser

        // Get client (browser) request data
        valread = read(new_socket, buffer, 1024);
        printf("%s\n", buffer);

        // Read URL from the HTTP-request and create HTML page
        bool send_404 = false;
        std::string content; // We save the HTML page on this variable
        std::stringstream http_header;
        http_header << buffer;
        std::string http_header_word;
        getline(http_header, http_header_word, ' ');
        if (http_header_word == "GET")
        {
            getline(http_header, http_header_word, ' ');
            http_header.str(http_header_word); // Save URL of the requested resource
            printf("This should be the URL: %s", http_header_word.c_str());
            getline(http_header, http_header_word, '/'); // Ignore first slash
            getline(http_header, http_header_word, '/');

            // We accept URLs with this structure:
            //  /api/[consumer,producer]/[id]
            if (http_header_word == "api")
            {
                getline(http_header, http_header_word, '/');
                if (http_header_word == "consumer")
                {
                    data_map_pointer = &consumer_data_map;
                    getline(http_header, http_header_word, '/');
                    // Convert ID to integer and see if we have it on list
                    try
                    {
                        if (consumer_data_map.find(stoi(http_header_word)) == consumer_data_map.end())
                        {
                            send_404 = true;
                            printf("ID %s wasn't found/wasn't a number", http_header_word.c_str());
                            content.append("<h2> We couldn't find a consumer with the ID " + http_header_word + " </h2></div> </html>");
                        }
                        else
                        {
                            content.append("<h1>Consumer: " + http_header_word + "</h1>\n");
                            auto const &pair = *data_map_pointer->find(stoi(http_header_word));
                            content.append("<table border=\"1\" cellspacing=\"0\"><thead><tr><th></th><th>Timestamp</th><th>Value</th></tr></thead>");
                            int index = 1;
                            for (auto &sec_pair : pair.second)
                            {
                                content.append("<tr><td>" + std::to_string(index) + "</td><td>" + sec_pair.timestamp + "</td><td>" + std::to_string(sec_pair.value) + "</td></tr>\n");
                                index++;
                            }
                            content.append("</table>");
                        }
                    }
                    catch (std::exception &err)
                    {
                        std::cout << "Conversion failure: " << err.what() << std::endl; // Note: what() tells the exact error
                    }
                }
                else if (http_header_word == "producer")
                {
                    data_map_pointer = &producer_data_map;
                    getline(http_header, http_header_word, '/');
                    // Convert ID to integer and see if we have it on list
                    try
                    {
                        if (producer_data_map.find(stoi(http_header_word)) == producer_data_map.end())
                        {
                            send_404 = true;
                            content.append("<h2> We couldn't find a producer with the ID " + http_header_word + " </h2></div> </html>");
                            printf("ID %s wasn't found/wasn't a number", http_header_word.c_str());
                        }
                        else
                        {
                            content.append("<h1>Producer: " + http_header_word + "</h1>\n");
                            auto const &pair = *data_map_pointer->find(stoi(http_header_word));
                            content.append("<table border=\"1\" cellspacing=\"0\"><thead><tr><th></th><th>Timestamp</th><th>Value</th></tr></thead>");
                            int index = 1;
                            for (auto &sec_pair : pair.second)
                            {
                                content.append("<tr><td>" + std::to_string(index) + "</td><td>" + sec_pair.timestamp + "</td><td>" + std::to_string(sec_pair.value) + "</td></tr>\n");
                                index++;
                            }
                            content.append("</table>");
                        }
                    }
                    catch (std::exception &err)
                    {
                        std::cout << "Conversion failure: " << err.what() << std::endl;
                    }
                }
                else
                {
                    send_404 = true;
                    content.append("<h2> Sorry, we don't have a client type named " + http_header_word + " </h2></div> </html>");
                    printf("It was %s and not consumer/producer", http_header_word.c_str());
                }
            }
            else
            {
                send_404 = true;
                content.append("<h2> We couldn't find a subsection named " + http_header_word + " </h2></div> </html>");
                printf("It was %s and not api", http_header_word.c_str());
            }
        }
        else
        {
            send_404 = true;
            content.append("<h2> This page can only responde to GET requests </h2></div> </html>");
            printf("Rejected! With: %s", http_header_word.c_str());
        }

        // Write the document back to the client
        std::ostringstream oss;
        if (send_404)
        {
            oss << "HTTP/1.1 404 NOT FOUND\r\n";
            content.insert(0, "<html><style type=\"text/css\"> body {background-color: #005792;color: #4caf50;font-family: monospace;} h1{font-size:15vw} h2{font-size: 5vw} div{margin-left: auto;margin-right: auto; width: 100em;text-align: center;}</style> <div><h1> 404 </h1> ");
        }
        else
        {
            oss << "HTTP/1.1 200 OK\r\n";
        }
        oss << "Cache-Control: no-cache, private\r\n";
        oss << "Content-Type: text/html\r\n";
        oss << "Content-Length: " << content.size() << "\r\n\r\n";
        oss << content;

        std::string output = oss.str();
        int size = output.size() + 1;

        send(new_socket, output.c_str(), size, 0);

        //send(new_socket, hello, strlen(hello), 0);
        printf("Hello message sent\n");
    }
}

