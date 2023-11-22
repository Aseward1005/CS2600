#include <stdio.h>
#include <mosquitto.h>

int main() {
    //client instantiation
    void* callbackPtr; //the callback pointer for the mosqitto instance
    char* id = NULL;
    bool clean_session = true;
    struct mosquitto* client = mosquitto_new(id, clean_session, callbackPtr); 

    //connect to client
    const char* host = "anthonyseward.duckdns.org";
    const int port = 1883;
    const int keepalive = 5;
    
    int connectionStatus = mosquitto_connect(client, host, port, keepalive);
    if (connectionStatus != MOSQ_ERR_SUCCESS) {
        printf("connection failed\n");
        return connectionStatus;
    }   
    
    //publish loop setup
    const char* topic = "LED_PROJECT/buttons";
    const char* on = "1";
    const char* off = "0";
    int payloadlen = 1;

    int choice;

    do {
        //user input
        printf("1 - on\n");
        printf("2 - off\n");
        printf("3 - exit\n");
        printf("enter: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: printf("publishing on\n");
                    mosquitto_publish(client, NULL, topic, payloadlen, on, 0, false);
                    break;
            case 2: printf("publishing off\n");
                    mosquitto_publish(client, NULL, topic, payloadlen, off, 0, false);
                    break;
            case 3: printf("later");
                    break;
            default: printf("invalid choice\n");
        }
    } while(choice != 3);
    return 0;
}
