#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <mosquitto.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_LEN 1024

int main()
{
    //MOSQUITTO SETUP
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

    const char* topic = "MUD_PROJECT/descriptions";   

    //SOCKET SETUP
    int sockfd, connfd;
    struct sockaddr_in servaddr, cliaddr;

    //create tcp socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    memset(&servaddr, 0, sizeof(servaddr));

    //fill server info
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    //bind socket with address and port
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0){
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    //listen for incoming connections
    if (listen(sockfd, 5) != 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }
    printf("Waiting for client to connect...\n");
    
    socklen_t len = sizeof(cliaddr);
    connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
    if (connfd < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
    printf("Client connected.\n");

    //GAME SETUP
    FILE *desc;
    char* startpoint = "/home/anthony_seward1005/CS2600/game/setting";
    if (chdir(startpoint) != 0) {
        perror("Error changing to initial directory");
        return 1;
    }

    unsigned int invalidTime = 3;
    char* invalid = "invalid move";
    int length;
    ssize_t bytesRead;

    char message[MAX_LEN];
    char description[MAX_LEN];
    while (message != "q") {
        //publish the description of the room
        desc = fopen("desc.txt", "r");
        fgets(description, sizeof(description), desc);
        fclose(desc);
	write(connfd, description, strlen(description));
        mosquitto_publish(client, NULL, topic, strlen(description), description, 0, false);

        //receive message from peer 1
        bytesRead = read(connfd, message, sizeof(message) - 1);
        //null terminate to treat this as a string
        message[bytesRead] = '\0';
        length = strlen(message);
        //printf("%d", length);
	//get rid of newline if its there
        if (len > 0 && message[length-1] == '\n')
            message[length - 1] = '\0';
        //if the directory doesnt exist, say invalid
	if (chdir(message) != 0) {
            char current_directory[256];
            if (getcwd(current_directory, sizeof(current_directory)) != NULL) {
                printf("Current Working Directory: %s\n", current_directory);
            } else {
                perror("Error getting current working directory");
                exit(EXIT_FAILURE);
            }
            perror("error changing to target directory");
            fprintf(stderr, "attempted to change to: %s\n", message);
            //return 1;
            mosquitto_publish(client, NULL, topic, strlen(invalid), invalid, 0, false);
            sleep(invalidTime);
        }

        //printf("%s", message);

        //send acknowledgment to the first player
        strcpy(message, "received\n");
        write(connfd, message, strlen(message));
    }

    close(sockfd);
    return 0;
}
