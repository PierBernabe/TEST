#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/time.h>

#define RCVSIZE 1024

int main (int argc, char *argv[]) {
  struct sockaddr_in adresse,client;
  socklen_t alen= sizeof(client);
  int port= atoi(argv[1]),valid= 1,recv_len,s,ack=1;
  char buffer[RCVSIZE],syn[3];

  //-----------------------------------------------------
  //           Create socket // handle error
  //-----------------------------------------------------
        if((s= socket(AF_INET, SOCK_DGRAM, 0))==-1){
            perror("cannot create socket1\n");
            return -1;
        }
        setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &valid, sizeof(int));
  //-----------------------------------------------------
  //              Initialisation structure
  //-----------------------------------------------------
        adresse.sin_family= AF_INET;
        adresse.sin_port= htons(port);
        adresse.sin_addr.s_addr= htonl(INADDR_ANY);
  //-----------------------------------------------------
  //                Bind socket to port
  //-----------------------------------------------------
        if (bind(s, (struct sockaddr*) &adresse, sizeof(adresse)) == -1) {
            perror("Bind fail\n");
            close(s);
            return -1;
        }
  //-----------------------------------------------------
  //              Keep listening for data
  //-----------------------------------------------------
        while (1) {
            //Executer à la première connection
            if(ack){
                printf("Waiting for connection ...\n");
                recvfrom(s,syn,4,0,(struct sockaddr *) &client, &alen);
                if(!strcmp("SYN", syn)){
                    printf("\tSynchronisation accepte \n");
                    sendto(s,"ACK\0",4,0,(struct sockaddr *) &client, sizeof(client));
                    ack=0;
                 }
            }
            //Executer après la synchronisation
            if(!ack){
                printf("Waiting for data ...\n");
                recvfrom(s,buffer,RCVSIZE,0,(struct sockaddr *) &client, &alen);
                printf("Data: %s\n",buffer);
                memset(buffer,0,RCVSIZE);
            }
        }
  //-----------------------------------------------------
  //                     Fermeture
  //-----------------------------------------------------
        close(s);
        return 0;
}