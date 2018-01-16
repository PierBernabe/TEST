MACHINE ASCENSEUR

/*? On modelise le systeme :
   - l'ensemble des portes ouvertes
   - l'etat de l'ascenseur (position et arret/mouvement)
   - les etages demandes
?*/

/*? Proprietes importantes :
  - l'ascenseur reste dans la limite des etages existants
  - si une porte est ouverte l'ascenseur est a l'arret en face
  - si l'ascenseur est arrete a l'etage pos l'appel a cet etage
    n'est  plus considere
?*/

/*? operations :

  - appeler, ouvrir, fermer : ces operations ne doivent pas
    avoir de precondition, l'utilisateur pouvant toujours faire
    ce qu'il veut.

  - deplacer : impossible si il y a une porte ouverte.

?*/

SETS
    MODE = { arret, mouv}

CONSTANTS
    max_etage, ETAGES

PROPERTIES
    max_etage : NAT1 & ETAGES=0..max_etage

VARIABLES

/*A COMPLETER*/

INVARIANT

/*A COMPLETER*/

INITIALISATION

/*A COMPLETER*/

OPERATIONS

/* on peut ouvrir une porte deja ouverte ou chercher a ouvrir
   une porte qui ne s'ouvrira pas */

    ouvrir (nn) =
        PRE
            nn : ETAGES
        THEN
            /*A COMPLETER*/
            skip
        END ;

/* on peut fermer une porte deja fermee */

    fermer (nn) =
        PRE
         nn : ETAGES
        THEN
            /*A COMPLETER*/
            skip
        END  ;
        

    appeler(nn) =
        PRE 
            nn : ETAGES
        THEN
            /*A COMPLETER*/
            skip
        END ;
    

/* l'ascenseur se trouve dans un mode et un etage quelconque.
   il a pu s'arreter en route et liberer des appels */

    deplacer =
        PRE
        THEN
        
        END
END

