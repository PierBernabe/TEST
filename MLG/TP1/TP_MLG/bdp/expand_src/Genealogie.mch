MACHINE
    Genealogie

SETS
    PERSONNES  /* Ensemble des personnes ayant existe ou qui existeront un jour */

CONCRETE_CONSTANTS
    H0 , F0    /* Ensemble des hommes et des femmes originaux. */
PROPERTIES
    H0 <: PERSONNES &
    F0 <: PERSONNES &
    H0 /\ F0 = {}

ABSTRACT_VARIABLES
    Hommes , Femmes , Pere , Mere
    /*, Maries*/

INVARIANT
    Hommes <: PERSONNES &
    Femmes <: PERSONNES &
    Hommes /\ Femmes = {} &
    /***** a completer *****/

    Pere : ( ( Hommes \/ Femmes ) - H0 - F0 ) --> Hommes &
    Mere : ( ( Hommes \/ Femmes ) - H0 - F0 ) --> Femmes
    /* Toute personne ayant un pere ou une mere en a au plus 1 de chaque */

    /* Un couple marie est necessairement forme d'un homme et d'une femme;    
       Chaque homme est marie au plus une fois;
       Chaque femme est mariee au plus une fois;
       Toute personne n'est pas necessairement mariee.
    */

    /* Deux parents d'une meme personne sont maries ensembles. */


INITIALISATION
    Hommes := H0 || Femmes := F0
    /***** a completer *****/
    || Pere := {} || Mere := {}

OPERATIONS
    /* Choisi une nouvelle personne et l'ajoute dans l'arborescence Pere / Mere */
    naitre ( pere , mere ) =
    PRE
       /***** a completer *****/
            pere : Hommes & mere : Femmes
    THEN
            /***** a completer *****/
            ANY alien WHERE
                alien : PERSONNES - Hommes - Femmes
            THEN
                Pere ( alien ) := pere ||
                Mere ( alien ) := mere ||
                CHOICE
                    Hommes := Hommes \/ { alien }
                OR
                    Femmes := Femmes \/ { alien }
                END
            END
        END

/*;
    

    / * Fait se marier 2 personnes * /
    marier(p1, p2) = 
    PRE
 	    / ***** a completer ***** /
    THEN
	    / ***** a completer ***** /
	END;
    
    
    / * Renvoie si une personne p1 est un descendant direct de p2 * /
    res <-- estParent(p1, p2) = 
    PRE 
 	    / ***** a completer ***** /
    THEN
 	    / ***** a completer ***** /
    END;
    
    
    
    / * Renvoie si une personne p1 est un descendant direct ou indirect de p2 * /
    res <-- estAncetre(p1, p2) = 
    PRE 
 	    / ***** a completer ***** /
    THEN
 	    / ***** a completer ***** /
    END
*/
END
