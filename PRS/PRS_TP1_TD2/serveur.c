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

  struct sockaddr_in adresse, adresse2,client;
  int port= atoi(argv[1]);
	int port2=8000;
  int valid= 1;
  socklen_t alen= sizeof(client);
  char buffer[RCVSIZE];

  //create socket
  int desc= socket(AF_INET, SOCK_STREAM, 0);
	int desc2= socket(AF_INET, SOCK_DGRAM, 0);

  // handle error
  if (desc < 0) {
    perror("cannot create socket1\n");
    return -1;
  }
	if (desc2 < 0) {
    perror("cannot create socket2\n");
    return -1;
  }

  setsockopt(desc, SOL_SOCKET, SO_REUSEADDR, &valid, sizeof(int));
  setsockopt(desc2, SOL_SOCKET, SO_REUSEADDR, &valid, sizeof(int));

  adresse.sin_family= AF_INET;
  adresse.sin_port= htons(port);
  adresse.sin_addr.s_addr= htonl(INADDR_ANY);

	adresse.sin_family= AF_INET;
  adresse.sin_port= htons(port2);
  adresse.sin_addr.s_addr= htonl(INADDR_ANY);

  if (bind(desc, (struct sockaddr*) &adresse, sizeof(adresse)) == -1) {
    perror("Bind fail\n");
    close(desc);
    return -1;
  }
	if (bind(desc2, (struct sockaddr*) &adresse2, sizeof(adresse2)) == -1) {
    perror("Bind fail\n");
    close(desc2);
    return -1;
  }


  if (listen(desc, 5) < 0) {
    printf("Listen failed\n");
    return -1;
  }
/*  if (listen(desc2, 5) < 0) {
    printf("Listen failed\n");
    return -1;
  }*/

	fd_set readset,writeset,exceptset;	
	int rqst;
  while (1) {
	FD_ZERO(&readset);	
	FD_ZERO(&writeset);
	FD_ZERO(&exceptset);
	FD_SET(desc,&readset);
	FD_SET(desc,&writeset);
	FD_SET(desc,&exceptset);
	FD_SET(desc2,&readset);
	FD_SET(desc2,&writeset);
	FD_SET(desc2,&exceptset);
	
	select(desc2 + 1, &readset, NULL, NULL, NULL);

  //int rqst= accept(desc, (struct sockaddr*)&client, &alen);
  //int pid = fork();
	//if(pid==0){
		
		//printf("Creation pocessus fils pid : %d ppid :%d\nsocket s : %d socket accept : %d\n",getpid(),getppid(),adresse,rqst);
			if(FD_ISSET(desc,&readset)){
			  rqst= accept(desc, (struct sockaddr*)&client, &alen);
		  	int msgSize= recv(rqst,buffer,RCVSIZE,0);
		
			  while (msgSize > 0) {
			    send(rqst,buffer,msgSize,0);
			    printf("%s",buffer);
			    memset(buffer,0,RCVSIZE);
			    msgSize= recv(rqst,buffer,RCVSIZE,0);
				}
	   }
		 else if(FD_ISSET(desc2,&readset)){
				printf("code udp");

		 }
		close(rqst);
	/*	exit(1);
	}
	close(rqst);*/
    

  }

close(desc);
return 0;
}







/*#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define DOMAIN AF_INET
#define TYPE SOCK_STREAM // pour TCP | SOCK_DGRAM pour UDP | SOCK_RAW si pas de protocole
#define PROTOCOLE 0 

int main (int args,char *argv[]){

	struct sockaddr_in myaddr,client;
	memset((char*)&myaddr, 0,sizeof(myaddr)); //remise à 0 memoire my_addr
		myaddr.sin_family=DOMAIN;
		myaddr.sin_port=htons(9000);
		myaddr.sin_addr.s_addr=(INADDR_ANY);
	socklen_t alen=sizeof(client);
	int tmp;
	int s=socket(DOMAIN,TYPE,PROTOCOLE);
	if(s==-1){
		printf("FAIL creation socket");
		return 1;
	}
	int reuse=1;
	setsockopt(s,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(reuse));
	printf("test");
	int b = bind(s,(struct sockaddr *)&myaddr,sizeof(myaddr));
	if(b==-1){
		printf("FAIL creation socket");
		return 1;
	}
	listen(s,10);
	while(1){
			printf("test");
		 if((tmp = accept(s,(struct sockaddr *)&client,&alen))<0){
			perror("erreur accept");
		}
		printf("%d test",tmp);
	}

	return 1;
}*/
