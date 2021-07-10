#ifndef GLOBALVARIABLES_H_CLIENT
#define GLOBALVARIABLES_H_CLIENT

#include "./dependencies/json.hpp"

#define TOPIC "client/client-status"
#define MQTT_HOST "172.20.0.11"
#define MQTT_PORT 1883
#define MQTTCLIENT_QOS2 1
#define DEFAULT_STACK_SIZE -1

bool CLIENT_RUNNING = true;
nlohmann::json client_data;
char CLIENT_ID[10];

#endif