#ifndef SS21_VERTEILTESYSTEME_DO1Y_HAMDANI_MENKE_MQTT_THREAD_H
#define SS21_VERTEILTESYSTEME_DO1Y_HAMDANI_MENKE_MQTT_THREAD_H

#include <signal.h>
#include <stdio.h>
#include <stdlib.h> // srand
#include <ctime>
#include <time.h>
#include <map>
#include <vector>
#include <stdint.h>
#include <string.h>
#include <mosquitto.h>
#include <sys/types.h>
#include <unistd.h>
#include "globalVariables.h"

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

    auto json_data = nlohmann::json::parse((char *)message->payload);

    // Pointer points to corresponding vector
    if (json_data.at("type") == "c") {
        data_map_pointer = &consumer_data_map;
    } else {
        data_map_pointer = &producer_data_map;
    }

    //parsing
    received_message received_msg;
    received_msg.value = json_data.at("value");
    received_msg.timestamp = json_data.at("timeStamp");
    received_msg.id = json_data.at("id");

    // Search if server doesn't know client
    if (data_map_pointer->find(json_data.at("id")) == data_map_pointer->end()) {
        // insert a new element if it's the first time to receive from this client
        data_map_pointer->insert(std::pair<int, std::vector<received_message>>(json_data.at("id"), std::vector<received_message>()));
        //and then pushback the received msg
        data_map_pointer->at(json_data.at("id")).push_back(received_msg);
    } else {
        // Save data on respective key
        data_map_pointer->at(json_data.at("id")).push_back(received_msg);
    }
}

void run_mqtt() {
    uint8_t reconnect = true;
    struct mosquitto *mosq;
    int rc = 0;

    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    mosquitto_lib_init();

    mosq = mosquitto_new("server", true, 0);

    mosquitto_connect_callback_set(mosq, connect_callback);
    mosquitto_message_callback_set(mosq, message_callback);

    rc = mosquitto_connect(mosq, MQTT_HOST, MQTT_PORT, 60);

    if (mosq) {
        // Serialize the structure to a json-string
        mosquitto_subscribe(mosq, NULL, TOPIC, 1);
        mosquitto_loop_forever(mosq,-1,1);
        while(run){
            if (run && rc) {
                printf("connection error!\n");
                sleep(10);
                mosquitto_reconnect(mosq);
            }
        }
    }
}

#endif