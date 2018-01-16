#ifndef IDENTIFIANT_UNIQUE
#define IDENTIFIANT_UNIQUE

void askFicName(char fic_name[]);
void extractLigne(char trame[]);
int sizeLigne(char trame[]);
int verif_checksum(char trame[]);
char verifCaract1(char trame[]);
char verif_trame(char trame[]);
void writeTrame(char num_fic,char trame[]);
int traitementTrame(char trame[],char trame_formater[]);
void removeFicDest();
void rapport();

#endif
