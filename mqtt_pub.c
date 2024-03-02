#include <stdio.h>
#include <string.h>
#include <mosquitto.h>

int main(){
    int rc;
    struct mosquitto * mosq;
    mosquitto_lib_init();
    mosq = mosquitto_new("publisher-test", true, NULL);
    rc = mosquitto_connect(mosq, "192.168.43.132", 1883, 60);
    if(rc !=0 ){
        printf("not connect");
        mosquitto_destroy(mosq);
        return -1;
    }
    printf("connected");
    char temp[100]; 
    printf("Enter message: ");
    scanf("%s", temp); 
    mosquitto_publish(mosq, NULL, "sw", strlen(temp), temp, 0, false);
    mosquitto_disconnect(mosq);
    mosquitto_destroy(mosq);
    mosquitto_lib_cleanup();
    return 0;
}
