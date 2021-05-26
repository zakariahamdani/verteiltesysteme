//
// Created by zpraktikawm on 24.05.21.
//
#include "globalVariables.h"

int tcpSockfd, new_socket, valread;
struct sockaddr_in address;
int opt = 1;
int addrlen = sizeof(address);
char tcpBuffer[MAXLINE] = {0};

std::string content; // We save the HTML page on this variable

bool send_404;

std::string HTTP_method;
std::string requestedURL;
std::string firstSlang;
std::string subDomain;
std::string participantType;
std::string participantId;

void setupTcpSocket();
void waitForConnection();
void parseRequest();
void constructParticipantHTML(std::string p_participantType, std::string p_participantId);
void constructHTML404Method();
void constructHTML404SubDomain();
void sendRespons();
std::string getStatus(int p_id);
long int getTimeStamp();

void http_server() {

    setupTcpSocket();

    while (true) {

        content = "";
        send_404 = false;

        // Here we wait for a connection to our socket
        waitForConnection();

        // Read URL from the HTTP-request and create HTML page
        parseRequest();
        printf("This should be the URL: %s", requestedURL.c_str());

        if (HTTP_method == "GET") {
            if (subDomain == "api") {
                constructParticipantHTML(participantType, participantId);
            } else {
                constructHTML404SubDomain();
            }
        } else {
            constructHTML404Method();
        }
        sendRespons();
    }
}

void setupTcpSocket() {
    // Create socket and attach it to the HTTP_PORT
    // Programm closes if we can't create-connect our socket to a port
    if ((tcpSockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(tcpSockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Accept connections from any IP
    address.sin_port = htons(HTTP_PORT);

    if (bind(tcpSockfd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
}

void waitForConnection() {
    if (listen(tcpSockfd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(tcpSockfd, (struct sockaddr *) &address,
                             (socklen_t * ) & addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    // At this point we already made a TCP connection with (probably) a browser
    // Get client (browser) request data
    valread = read(new_socket, tcpBuffer, 1024);
    printf("%s\n", tcpBuffer);
}

void parseRequest() {
    std::stringstream http_header;
    http_header << tcpBuffer;

    getline(http_header, HTTP_method, ' ');
    getline(http_header, requestedURL, ' ');

    http_header.str(requestedURL); // Save URL of the requested resource

    getline(http_header, firstSlang, '/'); // Ignore first slash
    getline(http_header, subDomain, '/');
    getline(http_header, participantType, '/');
    getline(http_header, participantId, '/');
}

void constructParticipantHTML(std::string p_participantType, std::string p_participantId) {
    std::string tableHeader;
    if (p_participantType == "consumer") {
        data_map_pointer = &consumer_data_map;
        tableHeader = "<table border=\"1\" cellspacing=\"0\"><thead><tr><th></th><th>Timestamp</th><th>consumed value in KW</th></tr></thead>";
    } else if (p_participantType == "producer") {
        data_map_pointer = &producer_data_map;
        tableHeader = "<table border=\"1\" cellspacing=\"0\"><thead><tr><th></th><th>Timestamp</th><th>produced value in KW</th></tr></thead>";
    } else {
        send_404 = true;
        content.append(
                "<h2> Sorry, we don't have a participant type named " + p_participantType + " </h2></div> </html>");
        printf("It was %s and not consumer/producer", p_participantType.c_str());
        return;
    }

    try {
        if (data_map_pointer->find(stoi(p_participantId)) == data_map_pointer->end()) {
            send_404 = true;
            printf("ID %s wasn't found/wasn't a number", p_participantId.c_str());
            content.append("<h2> We couldn't find a" + p_participantType + " with the ID: " + p_participantId + " </h2></div> </html>");
        } else {
            content.append("<h1>" + p_participantType + ": " + p_participantId + " State: " + getStatus(stoi(p_participantId)) + "</h1>\n");
            auto const &pair = *data_map_pointer->find(stoi(p_participantId));
            content.append(tableHeader);
            int index = 1;
            for (auto &sec_pair : pair.second) {
                content.append("<tr><td>" + std::to_string(index) + "</td><td>" + std::ctime(&sec_pair.timestamp) + "</td><td style=\"text-align:center\">" +
                               std::to_string(sec_pair.value) + "</td></tr>\n");
                index++;
            }
            content.append("</table>");
        }
    }
    catch (std::exception &err) {
        std::cout << "Conversion failure: " << err.what() << std::endl; // Note: what() tells the exact error
    }
}

void constructHTML404Method(){
    send_404 = true;
    content.append("<h2> This page can only responde to GET requests </h2></div> </html>");
    printf("Rejected! With: %s", HTTP_method.c_str());
}

void constructHTML404SubDomain(){
    send_404 = true;
    if(subDomain == ""){
        content.append("<h2> Main page not found </h2></div> </html>");
    } else {
        content.append("<h2> We couldn't find a subsection named " + subDomain + " </h2></div> </html>");
    }
    printf("It was %s and not api", subDomain.c_str());
}

void sendRespons(){
    // Write the document back to the client
    std::ostringstream oss;
    if (send_404) {
        oss << "HTTP/1.1 404 NOT FOUND\r\n";
        content.insert(0,
                       "<html><style type=\"text/css\"> body {background-color: #005792;color: #4caf50;font-family: monospace;} h1{font-size:10vw} h2{font-size: 2vw} div{margin-left: auto;margin-right: auto; width: 100em;text-align: center;}</style> <div><h1> 404 </h1> ");
    } else {
        oss << "HTTP/1.1 200 OK\r\n";
    }
    oss << "Cache-Control: no-cache, private\r\n";
    oss << "Content-Type: text/html\r\n";
    oss << "Content-Length: " << content.size() << "\r\n\r\n";
    oss << content;

    std::string output = oss.str();
    int size = output.size() + 1;

    send(new_socket, output.c_str(), size, 0);
}

std::string getStatus(int p_id){
    int  diff = getTimeStamp() - data_map_pointer->find(p_id)->second.back().timestamp;

    if(diff > 5){
        return "offline since:" + std::to_string(data_map_pointer->find(p_id)->second.back().timestamp);
    }else{
        return "online";
    }

}

long int getTimeStamp()
{
    return static_cast<long int>(std::time(nullptr));
}