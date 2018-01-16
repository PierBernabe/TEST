#include <stdio.h>
#include <stdlib.h>
#include "mediane.h"

int main(void){

	int tab[10]={5,3,4,1,6,8,7,9,1,1};
	double num_mediane=mediane(tab, 10);

	printf("La mediane du tableau est %f\n",num_mediane);





	return 0;
}
