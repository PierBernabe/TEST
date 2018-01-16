#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define RCVSIZE 1024

int main (int argc, char *argv[]) {
    struct sockaddr_in adresse;
    int port= atoi(argv[2]),valid= 1,s,a=1,ack=1;
    char msg[RCVSIZE],rep[3];
  //-----------------------------------------------------
  //           Create socket // handle error
  //-----------------------------------------------------
        if((s= socket(AF_INET, SOCK_DGRAM, 0))<3){
            perror("cannot create socket\n");
            return -1;
        }
        setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &valid, sizeof(int));
  //-----------------------------------------------------
  //              Initialisation structure
  //-----------------------------------------------------
        adresse.sin_family= AF_INET;
        adresse.sin_port= htons(port);
        //adresse.sin_addr.s_addr= htonl(INADDR_LOOPBACK);
        inet_aton(argv[1],&adresse.sin_addr);
  //-----------------------------------------------------
  //                 Envoi des messages
  //-----------------------------------------------------
        while(a){
            printf("Enter message :");
            fgets(msg, RCVSIZE, stdin);
            //Quitte le client
            if(strcmp(msg,"stop\n") == 0){
                a--; 
            }
            //Synchronisation avec le serveur
            if(ack){
                sendto(s,"SYN\0",4,0,(struct sockaddr *) &adresse, sizeof(adresse));
                recv(s,rep,4,0);
                if(!strcmp("ACK", rep)){printf("Connection reussi\n");ack--;}
                else{printf("Connection fail\n");close(s);return -1;}
            }
            //envoi data
            sendto(s,msg,strlen(msg),0,(struct sockaddr *) &adresse, sizeof(adresse));    
        }
  //-----------------------------------------------------
  //                     Fermeture
  //-----------------------------------------------------
        close(s);
        return 0;
}