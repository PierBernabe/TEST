#include<sys/types.h>
#include<sys/stat.h>
#include<sys/fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<signal.h>


int main(){
	char c='a';int p;
	struct stat bufstat;
	p=open("tube",O_RDONLY);
	if(p==-1){printf("erreur ouveture tube\n");return 0;}
	fstat("tube",&bufstat);

	for(;;){
		//if(bufstat.st_size>=4){		//marche pas	
			//while(c!=EOF){
				read(p,&c,1);
				if(c=='-'){break;}
				printf("%c",c);
				//putchar(c);
				//(void)getchar();		
			//}
			//if(c=='-'){break;}	
		//}
		printf("\n");
	sleep(1);
	}


	return 0;
}
