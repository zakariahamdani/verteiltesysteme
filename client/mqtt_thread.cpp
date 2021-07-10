#include <signal.h>
#include <stdio.h>
#include <stdlib.h> // srand
#include <ctime>
#include <time.h>
#include <stdint.h>
#include <string.h>
#include <mosquitto.h>
#include <sys/types.h>
#include <unistd.h>
#include "globalVariables.h"

#define CLIENTID "Publisher"
#define PAYLOAD "Hello World!"

static int run = 1;

void handle_signal(int s) {
    run = 0;
}

void connect_callback(struct mosquitto *mosq, void *obj, int result) {
    printf("connect callback, rc=%d\n", result);
}

void message_callback(struct mosquitto *mosq, void *obj, const struct mosquitto_message *message) {
    bool match = 0;
    printf("got message '%.*s' for topic '%s'\n", message->payloadlen, (char *)message->payload, message->topic);

    mosquitto_topic_matches_sub(TOPIC, message->topic, &match);
    if (match)
    {
        printf("got message for ADC topic\n");
    }
}

long int getTimeStamp() {return static_cast<long int>(std::time(nullptr));}

void run_mqtt(int clientid)
{
    uint8_t reconnect = true;
    struct mosquitto *mosq;
    int rc = 0;

    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    mosquitto_lib_init();

    std::string s = std::to_string(clientid);
    char const *clientid_char = s.c_str();
    mosq = mosquitto_new(clientid_char, true, 0);

    mosquitto_connect_callback_set(mosq, connect_callback);
    mosquitto_message_callback_set(mosq, message_callback);

    rc = mosquitto_connect(mosq, MQTT_HOST, MQTT_PORT, 60);

    //mosquitto_subscribe(mosq, NULL, "/devices/wb-adc/controls/+", 0);

    srand(client_data["id"]);
    while (true) {
        if(CLIENT_RUNNING == false){
            continue;
        }
        // Create data to send
        int value = rand()%1000;
        client_data["value"] = value;
        client_data["timeStamp"] = getTimeStamp();
        // Serialize the structure to a json-string
        char serialized[client_data.dump().length()]; // Create a char[] big enough to hold our serialized str
        strcpy(serialized, client_data.dump().c_str()); // Save the serialized str on that created variable

        mosquitto_publish(mosq, NULL, TOPIC, strlen(serialized), serialized, 1, false);

        sleep(2);

        if (run && rc)
        {
            printf("connection error!\n");
            sleep(10);
            mosquitto_reconnect(mosq);
        }
    }
}