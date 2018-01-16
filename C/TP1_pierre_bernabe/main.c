#include <stdio.h>
#include "TP1_function.h"
#define TAILLE_MAX_TRAME 64
#define MAX_NB_FIC 5


/****************************************************************************/
/*                                                                          */
/*                                 main                                     */
/*                                                                          */
/****************************************************************************/
int main(void){
    char trame[TAILLE_MAX_TRAME],trame_formater[TAILLE_MAX_TRAME], fic_name[20];
    char num_fic;
    int a=0;

    askFicName(fic_name);
    removeFicDest();
    extractLigne(trame);
    while(trame[0]!='\0'){			//extactLigne affect '\0' si end of file
        num_fic=verif_trame(trame);
        while(a==0){
            a=traitementTrame(trame,trame_formater);
            writeTrame(num_fic,trame_formater);
        }
        extractLigne(trame);
        a=0;
    }
    rapport();

    return 0;
}
