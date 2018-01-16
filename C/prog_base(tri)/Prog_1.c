#include<stdio.h>
int main(){
	
	int n=10,i,t1[n],t2[n];
	float t3[n];
	for(i=0;i<n;i++){
		t1[i]=i*2+1;
		t2[i]=i*2;
		t3[i]=(float)t1[i]/t2[i];
		printf("t1=%d | t2=%d | t1/t2=%f\n",t1[i],t2[i],t3[i]);
	}
	return 0;
}
