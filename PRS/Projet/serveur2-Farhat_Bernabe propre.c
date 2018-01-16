#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/time.h>

//Activation des differents protocoles
#define SLOW_START TRUE
#define DEBUG 1

#define RTT 12500
#define RCVSIZE 1500
#define SIZEDATA 1494
#define MAXWINDOWS 100
struct sockaddr_in adresse,client;
//--------------------------------------------------------------------------------------
//------------------------------     createSocketUDP     -------------------------------
//--------------------------------------------------------------------------------------
int createSocketUDP(int port){
  int s,valid= 1;
  //struct sockaddr_in adresse;
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
        //inet_aton("8.8.8.8",&adresse.sin_addr);
  //-----------------------------------------------------
  //                Bind socket to port
  //-----------------------------------------------------
        if (bind(s, (struct sockaddr*) &adresse, sizeof(adresse)) == -1) {
            perror("Bind fail\n");
            close(s);
            return -1;
        }
  return s;
}
//--------------------------------------------------------------------------------------
//------------------------------     synchronisation     -------------------------------
//--------------------------------------------------------------------------------------
int synchronisation(char *portchar,int s,socklen_t alen){
    //-----------------------------------------------------
    //                Envoi SYN-ACK && NewPort
    //-----------------------------------------------------
    char synAck[12]={'S','Y','N','-','A','C','K',portchar[0],portchar[1],portchar[2],portchar[3],'\0'},syn[4];
    printf("Main > SYN-ACK send %s\n",synAck);
    sendto(s,synAck,12,0,(struct sockaddr *) &client, sizeof(client));
    printf("Main > Waiting for ACK ...\n");
    //-----------------------------------------------------
    //                   Attente ACK
    //-----------------------------------------------------
    recvfrom(s,syn,4,0,(struct sockaddr *) &client, &alen);
    if(strcmp("ACK", syn)){ close(s);printf("error ACK");return -1;}
    memset(syn,0,4);
    return 0;
}
//--------------------------------------------------------------------------------------
//-----------------------    Nombre de caractere dans le fichier   ---------------------
//--------------------------------------------------------------------------------------
int sizeFic(char * nomFic){
    FILE *fp;
    //-----------------------------------------------------
    //            Ouverture du fichier
    //-----------------------------------------------------
    if ((fp = fopen(nomFic,"rb")) == NULL) {
        fprintf(stderr,"Impossible d'ouvrir le fichier données en lecture\n");
        exit(1);
    }
    int size=0;
    char c;
    //-----------------------------------------------------
    //            Count le nombre de caractere
    //-----------------------------------------------------
    while(fscanf(fp,"%c",&c) != EOF){
        size++;
    }
    fclose(fp);
    printf("size = %d\n",size);
    return size;
}
//--------------------------------------------------------------------------------------
//----------------------    Ecriture d'un fichier dans un tab de bytes    --------------
//--------------------------------------------------------------------------------------
void ficToTab(char* fic,char* nomFic,int size){
    FILE *fp;
    printf("recuperation des données\n");
    if ((fp = fopen(nomFic,"rb")) == NULL) {
        fprintf(stderr,"Impossible d'ouvrir le fichier données en lecture\n");
        exit(1);
    }
    int i=0;
    char c;
    fread(fic, 1, size*sizeof(char), fp);
    fclose(fp);
}
//--------------------------------------------------------------------------------------
//----------------------    Retourne ne numero de la sequence en int   -----------------
//--------------------------------------------------------------------------------------
int stringToInt(char* seq){
    char tmp[7]={seq[3],seq[4],seq[5],seq[6],seq[7],seq[8],'\0'};
    return atoi(tmp);
}
//--------------------------------------------------------------------------------------
//----------------    Formatage de la trame retourne le nb de caractère    -------------
//--------------------------------------------------------------------------------------
void formatageTrame(char* seqString,int seq,char* tmp,char* trame,int size,char* fic, int indicelastSeq){
    int i;
    //-----------------------------------------------------
    //         Récuperation sequence et data
    //-----------------------------------------------------
    sprintf(seqString,"%06d",seq);
    for(i=0;i<6;i++){
        trame[i]=seqString[i];
    }
    for(i=0;i<SIZEDATA && size!=seq*SIZEDATA+i-SIZEDATA;i++){
        trame[i+6]=fic[seq*SIZEDATA+i-SIZEDATA];
    }
}
//--------------------------------------------------------------------------------------
//----------------------    Send FIN pour indiquer la fin du fichier1   ----------------
//--------------------------------------------------------------------------------------
void sendFin(int s, socklen_t alen){
    char ack[4];
    printf("> Envoi FIN\n");
    sendto(s,"FIN\0",4,0,(struct sockaddr *) &client, sizeof(client));
    recvfrom(s,ack,4,0,(struct sockaddr *) &client, &alen);
    if(!strcmp("ACK",ack)){
        printf("ACK mauvais\n");
        exit(1);
    }
    else{
        printf("fichier correctement transmit");
        exit(1); 
    }
}
//--------------------------------------------------------------------------------------
//------------------------------    Envoi du fichier au client    ----------------------
//--------------------------------------------------------------------------------------
void sendFic(char* fic,int size,socklen_t alen,int s){
    char trame[RCVSIZE],seqString[6],ack[9],tmp[9];
    int seq=0,i=0,newACK=0,ACKvalide=0,posInFic=0,count=0,tinfs,w=0,ACKproblem=-2,lastseq=-1,h;
    int windows = 1,SSTHRESH=1000,tmpSSTHRESH=1000,bufferFide=1,attente=0,maxSeqSend=0,bug=0,seqRTT=1,ACKproblemCount=0;
    struct timeval timeBefore,timeAfter,tv;
    struct timeval temps_avant, temps_apres;
    gettimeofday (&temps_avant, NULL);
    int indicelastSeq=(int)((size/SIZEDATA)-((size%SIZEDATA)/SIZEDATA));
    if((size%SIZEDATA)!=0){
        indicelastSeq++;
    }
    if(indicelastSeq==1){formatageTrame(seqString,1,tmp,trame,size,fic,indicelastSeq);lastseq=1;}
    printf("Nbre de trame à envoyer = %d\n",indicelastSeq);
    while(1){
        if(attente){
            //if(DEBUG)printf("---ATTENTE---\n");
            attente=0;
            tv.tv_sec=0;
            tv.tv_usec=RTT;
        }
        else{
            //if(DEBUG)printf("---NO ATTENTE---\n");
            tv.tv_sec=0;
            tv.tv_usec=1;
        }
        fd_set readset;
        FD_ZERO(&readset);
        FD_SET(s, &readset);
        select(s+1, &readset,NULL,NULL,&tv);
        //-----------------------------------------------------
        //               reception des données
        //-----------------------------------------------------
            if(FD_ISSET(s, &readset)){
                recvfrom(s,ack,9,0,(struct sockaddr *) &client, &alen);
                newACK=stringToInt(ack);
                if(newACK==indicelastSeq){for(h = 0;h<10;h++){sendFin(s,alen);}}
                else if(newACK>ACKvalide){
                    if(DEBUG)printf("valide %d\n",newACK);
                    w-=newACK-ACKvalide;
                    if(windows<tmpSSTHRESH) windows+=(newACK-ACKvalide)*2;
                    else windows+=1;
                    ACKproblemCount=0;
                    ACKvalide=newACK;
                }
                else if(newACK==ACKvalide){
                    ACKproblem=newACK;
                    ACKproblemCount++;
                    if(DEBUG){printf("ACKprblem -> %d\n",ACKproblem);}
                } 
                else if(DEBUG){printf("Nouvelle ACK inutile\n");} 
                if(ACKvalide==maxSeqSend) 
                    bufferFide=1;
                attente=0;
                count=0;
            }
            else{ 
                count++;
                //if(DEBUG){printf("count > %d\n",count);}
                if(count==3 || ACKproblemCount>1){
                    tmpSSTHRESH=((maxSeqSend-ACKvalide)/2)-(((maxSeqSend-ACKvalide)%2)/2)+1;
                    if(DEBUG)printf("new SSTHRESH = %d\n",tmpSSTHRESH);
                    count=0;
                    ACKproblemCount=0;
                    w=0;windows=1;
                    if(DEBUG)printf("new windows = %d\n",windows);
                    bug=1;
                    //seq=ACKvalide;
                    //if(DEBUG)printf("ACK = %d\n",ACKvalide); 
                }
                bufferFide=1;
                attente=1;
            }
        //-----------------------------------------------------
        //             Envoi de la derniere trame
        //-----------------------------------------------------
        if(lastseq==ACKvalide+1 && bufferFide){
            seq++;
            formatageTrame(seqString,seq,tmp,trame,size,fic,indicelastSeq);
            tinfs=size%SIZEDATA+6;
            if(DEBUG){printf("taille de la trame =%d\n",tinfs);}
            char tab[tinfs];
            for(i=0;i<tinfs;i++){tab[i]=trame[i];}
            sendto(s,tab,tinfs,0,(struct sockaddr *) &client, sizeof(client));
            if(DEBUG){printf("Derniere trame %d envoyée\n",lastseq);}
            printf("ACK = %s\n",ack);
            bufferFide=0;          
            attente=1; 
        }
        //-----------------------------------------------------
        //                  Envoi des données
        //-----------------------------------------------------
        if(w<0){w=0;}
        if(windows>100){windows=100;}
        if(bufferFide && lastseq!=ACKvalide+1){
            for(w;w<windows;w++){
                //if(DEBUG)printf("%d == %d",ACKproblem,ACKvalide);
                if(bug){
                    if(ACKvalide+1!=indicelastSeq){
                        if(DEBUG){printf("Renvoie de la trame %d\n",ACKvalide+1);}     
                        formatageTrame(seqString,ACKvalide+1,tmp,trame,size,fic,indicelastSeq);
                        sendto(s,trame,RCVSIZE,0,(struct sockaddr *) &client, sizeof(client));
                        //if(DEBUG){printf("Send %d\n",ACKvalide+1);}
                    }
                    else{
                        w=windows;
                        lastseq=ACKvalide+1;
                    }
                }
                else{
                    //if(DEBUG)printf("%d => %d\n",w,windows);
                    if(seq+1!=indicelastSeq){
                        seq++;
                        if(seq%10000==0)printf("send %d\n",seq);
                        formatageTrame(seqString,seq,tmp,trame,size,fic,indicelastSeq);
                        if(seq!=indicelastSeq){
                            sendto(s,trame,RCVSIZE,0,(struct sockaddr *) &client, sizeof(client));
                            if(DEBUG){printf("Send %d\n",seq);}
                        }else{
                            w=windows;
                            lastseq=seq;
                        }
                        maxSeqSend=seq;
                        //-------------------------------------------------------------------------
                    //-------------------------------------------------------------------------
                    tv.tv_sec=0;
                    tv.tv_usec=1;
                    FD_ZERO(&readset);
                    FD_SET(s, &readset);
                    select(s+1, &readset,NULL,NULL,&tv);
                    if(FD_ISSET(s, &readset)){
                        recvfrom(s,ack,9,0,(struct sockaddr *) &client, &alen);
                        newACK=stringToInt(ack);
                        if(newACK==indicelastSeq){for(h = 0;h<10;h++){sendFin(s,alen);}}
                        else if(newACK>ACKvalide){
                            if(DEBUG){printf("Valide in Send %d\n",newACK);}
                            w-=newACK-ACKvalide;
                            if(windows<tmpSSTHRESH) windows+=(newACK-ACKvalide)*2;
                            else windows+=1;
                            ACKproblemCount=0;
                            ACKvalide=newACK;
                        }
                        else if(newACK==ACKvalide){
                            ACKproblem=newACK;
                            ACKproblemCount++;
                        }else 
                        if(DEBUG){printf("Nouvelle ACK inutile\n");}
                        if(ACKvalide>seq)seq=ACKvalide;
                    }
                    if(ACKvalide>ACKproblemCount)ACKproblemCount=0;
                    if(ACKproblemCount==3){
                        tmpSSTHRESH=((maxSeqSend-ACKvalide)/2)-(((maxSeqSend-ACKvalide)%2)/2)+1;
                        if(DEBUG)printf("new SSTHRESH = %d\n",tmpSSTHRESH);
                        ACKproblemCount=0;
                        w=0;windows=1;
                        if(DEBUG)printf("new windows = %d\n",windows);
                        bug=1;
                        seq=ACKvalide;
                    }
                    //-------------------------------------------------------------------------
                    //-------------------------------------------------------------------------
                    }
                }
                count=0;
            }
            bufferFide=0;
            //gettimeofday (&temps_apres, NULL);
            //long int t=((temps_apres.tv_sec - temps_avant.tv_sec) * 1000000 + temps_apres.tv_usec) - temps_avant.tv_usec;
            //if (RTT < t || bug) attente++;
            //temps_avant=temps_apres;
            bug=0;
        }
    }
}
//--------------------------------------------------------------------------------------
//-----------------------------------     MAIN     -------------------------------------
//--------------------------------------------------------------------------------------
int main (int argc, char *argv[]) {
  socklen_t alen= sizeof(client);
  int port= atoi(argv[1]),recv_len,s,ack=1,pid=1,newport,count=1,a;
  char buffer[RCVSIZE],syn[4],portchar[5];
  //-----------------------------------------------------
  //            Creation du socket principal
  //-----------------------------------------------------
        if ((s=createSocketUDP(port)) == -1){
            fprintf(stderr,"fail create socket\n");
            exit(2);
        }
  //-----------------------------------------------------
  //              Keep listening for data
  //-----------------------------------------------------
        while (1) {
            //-----------------------------------------------------
            //                Code du port public
            //-----------------------------------------------------
            if(pid!=0){
                printf("Main > Waiting for connection ...\n");
                recvfrom(s,syn,4,0,(struct sockaddr *) &client, &alen);
                if(!strcmp("SYN", syn)){
                    printf("Main > Synchronisation accepte \n");
                    //-----------------------------------------------------
                    //         generation NewPort && Creation fils
                    //-----------------------------------------------------
                    newport=port+count;count++;
                    sprintf(portchar, "%d",newport);
                    //-----------------------------------------------------
                    //            Phase de synchronisation
                    //-----------------------------------------------------
                    pid=fork();
                    if(pid!=0){
                        if ((a=synchronisation(portchar,s,alen)) == -1){
                            fprintf(stderr,"fail synchronisation\n");
                            exit(2);
                        }
                        printf("Main > Synchronisation reussi \n");
                    }
                }
                
            }
            memset(syn,0,4);
            //-----------------------------------------------------
            //                   Code du port privé
            //-----------------------------------------------------
            if(pid==0){
                printf("%s > Execution code fils, > pid = %d\n",portchar,getpid());
                if(ack){      //Ne s'execute qu'une seule fois
                    close(s);
                    //-----------------------------------------------------
                    //            Creation du socket privé
                    //-----------------------------------------------------
                    if ((s=createSocketUDP(newport)) == -1){
                        fprintf(stderr,"fail create socket\n");
                        exit(2);
                    }
                    ack=0;
                }
                else{
                    //-----------------------------------------------------
                    //            Boucle attend nom du fichier
                    //-----------------------------------------------------
                    printf("%d > Waiting for name FIC ...\n",newport);
                    recvfrom(s,buffer,RCVSIZE,0,(struct sockaddr *) &client, &alen);
                    printf("%d > Fichier: %s\n",newport,buffer);
                    //-----------------------------------------------------
                    //              Recuperation des données
                    //-----------------------------------------------------
                    int size = sizeFic(buffer);
                    char * fic = (char*)malloc(size*sizeof(char));
                    ficToTab(fic,buffer,size);
                    memset(buffer,0,RCVSIZE);
                    //--------  ---------------------------------------------
                    //            Envoi des données par trame
                    //-----------------------------------------------------
                    sendFic(fic,size,alen,s);
                    free(fic);
                }
            }
            
        }
  //-----------------------------------------------------
  //                     Fermeture
  //-----------------------------------------------------
        close(s);
        return 0;
}