#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void fct(){
	printf("Interuption");
}

int main(){
	int a;
	printf("Saisir durée pause\n");
	scanf("%d",&a);
	signal(SIGALRM,fct);
	alarm(a);
	pause();
	printf("REVEIL");
	return 0;
}






