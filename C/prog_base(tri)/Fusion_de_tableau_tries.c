#include<stdio.h>
int main(){
	int n=10;
	int T[10]={1,5,7,8,8,8,9,10,10,13},S[10]={1,5,7,8,8,8,9,10,10,13},TS[20],i=0,j=0,s=0,x;
	while(i<n && j<n){
		if(T[i]<=S[j]){
			TS[s]=T[i];i++;s++;		
		}
		if(T[i]>S[j]){
			TS[s]=S[j];j++;s++;		
		}
	}
	for(x=i;x<n;x++){
		TS[s]=T[i];s++;i++;	
	}
	for(x=j;x<n;x++){
		TS[s]=S[j];s++;j++;	
	}
	for(s=0;s<n*2;s++){
		printf("%d\n",TS[s]);
	}
return 0;
}
