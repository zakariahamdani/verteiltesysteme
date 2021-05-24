//
// Created by zpraktikawm on 24.05.21.
//

#ifndef SS21_VERTEILTESYSTEME_DO1Y_HAMDANI_MENKE_GLOBALVARIABLES_H
#define SS21_VERTEILTESYSTEME_DO1Y_HAMDANI_MENKE_GLOBALVARIABLES_H

#define UDP_PORT 55443
#define HTTP_PORT 8001
#define MAXLINE 1024

struct received_message
{
    std::string timestamp;
    int value;
    int id;
};
std::map<int, std::vector<received_message>> producer_data_map;
std::map<int, std::vector<received_message>> consumer_data_map;
std::map<int, std::vector<received_message>> *data_map_pointer;

#endif //SS21_VERTEILTESYSTEME_DO1Y_HAMDANI_MENKE_GLOBALVARIABLES_H
