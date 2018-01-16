#include<stdio.h>
#define N 10
int main(){
	int Tab[N]={5,8,4,7,6,8,2,3,4,8},l=N;
	Trifusion(*Tab[N],L); 






	return 0;
}

/************************************************************************************************/
/*																								*/
/*		But:																					*/
/*			Trier un tableau																	*/
/*																								*/
/*		Interface :																				*/
/*			T[]  Tableau à trier																*/
/*			L 	 Longueur du tableau															*/
/*			 																					*/
/*																								*/
/************************************************************************************************/
Trifusion(int *T[N],int L{
	




}

/************************************************************************************************/
/*																								*/
/*		But:																					*/
/*			Fusionner deux tableaux dans un troisième											*/
/*																								*/
/*		Interface																				*/
/*			T[] premier tableau																	*/
/*			S[] second  tableau																	*/
/*			TS[] tableau fusionner																*/
/*																								*/
/************************************************************************************************/
fusion_de _tableau_tries(int *T[n],int *S[n],int *TS[2*n]){
	int n=10;
	int T[10]={1,5,7,8,8,8,9,10,10,13},S[10]={1,5,7,8,8,8,9,10,10,13},TS[20],i=0,j=0,s=0,x;
	while(i<n-1 && j<n-1){
		if(T[i]<=S[j]){
			TS[s]=T[i];i++;s++;		
		}
		if(T[i]>S[j]){
			TS[s]=S[j];j++;s++;		
		}
	}
	for(x=i;x<n-1;x++){
		TS[s]=T[i];s++;i++;	
	}
	for(x=j;x<n-1;x++){
		TS[s]=S[j];s++;j++;	
	}
	

	for(s=0;s<n*2-1;s++){
		printf("%d\n",TS[s]);
	}

}
