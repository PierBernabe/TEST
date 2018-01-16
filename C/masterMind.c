#include<stdio.h>
#include<stdlib.h>
int main(){
	int i,j=0,a=0,try[3],alea[3],alea1[3],try1[3],perfect,moyen,ii;
	alea[0]=6;alea[1]=4;alea[2]=2;alea[3]=6;	
	for(i=0;i<4;i++){
		printf(" \n%d ",alea[i]);
	}
	while(a==0){
		j++;
		perfect=0;
		moyen=0;
		a=0;
		printf("\nSaisir 4 chiffres (0-9)\n");
		scanf("%d %d %d %d",&try[0],&try[1],&try[2],&try[3]);
		for(i=0;i<4;i++){			
			alea1[i]=alea[i];
			try1[i]=try[i];
			if(alea1[i]==try1[i]){
				perfect++;
				alea1[i]=i+16*i+16;
				try1[i]=i+121*i+121;
			}
		}
		for(i=0;i<4;i++){
			for(ii=0;ii<4;ii++){
				if(alea1[i]==try1[ii]){
				moyen++;
				alea1[i]=i+1349*i+1349;
				try1[ii]=i+10587*i+10587;
				}
			}
		}
		printf("\n%d chiffres sont bien placés\n%d chiffres sont mal placés\n",perfect,moyen);
		if(perfect==4){a++;}	
	}
	printf("BRAVO!!!!\nVous avez trouvé en %d essais\n",j);
	return 0;
}
