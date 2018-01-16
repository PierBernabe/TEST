#include <stdio.h>
#include <stdlib.h>
#include "hanoi.h"
#include "pile.h"
#include "pile_type.h"

int deplacer(PILE *psource, PILE *pdest){
	
	if((*pdest)==0){
		Empiler(pdest,(*psource)->elem);
		Depiler(psource);
		return 0;
	}
	if((*psource)->elem<(*pdest)->elem){
		Empiler(pdest,(*psource)->elem);
		Depiler(psource);
	}
	else error1("Déplacement impossible\n");
	
	return 0;
}

int hanoi(PILE *depart,PILE *passage, PILE *arrive,int N){
	
	if(N>1){
		hanoi(depart,arrive,passage,N-1);
		deplacer(depart,arrive);
		hanoi(passage,depart,arrive,N-1);
	}
	if(N==1){
		deplacer(depart,arrive);
	}
	return 0;
}
