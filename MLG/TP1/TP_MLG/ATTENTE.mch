/* 
   Machine permettant de gerer des demandes differentes.
   Bornee par nb_max

   A PROUVER EN FORCE 1
   
   Étudier l'obligation de preuve non déchargée et se convaincre qu'elle est correcte.
*/

MACHINE ATTENTE

SETS VAL

CONSTANTS
   nb_max

PROPERTIES
   nb_max : 1.. MAXINT

VARIABLES  
   attente, nb_elem           

INVARIANT  
   attente <: VAL & nb_elem : NAT &  nb_elem <= nb_max & attente: FIN(attente)  & nb_elem=card(attente)


INITIALISATION 
   nb_elem := 0 || attente := {}


OPERATIONS  
    nb <-- nb_attente =
    BEGIN
    	nb := nb_elem
	END;

	ajouter(vv)  =
	PRE 
	    vv : VAL & vv /:attente & nb_elem/=nb_max
    THEN 
        attente := attente \/ {vv}   || nb_elem:=nb_elem+1 
    END ;

	vv <-- traiter  =
	PRE  
	    attente/={}
    THEN 
        ANY val WHERE 
            val : VAL & val : attente 
        THEN 
            vv:=val 
      		|| attente := attente - {val}
      		|| nb_elem := nb_elem-1
      	END
    END
END
