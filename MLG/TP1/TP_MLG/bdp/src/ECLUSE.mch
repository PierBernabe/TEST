MACHINE

    ECLUSE

SETS

    NIVEAU = { haut , bas } ;
    PORTE = { ouverte , fermee }

ABSTRACT_VARIABLES

    sas ,               /* niveau de l'eau dans le sas */
    pav ,               /* etat de la porte aval */
    pam                        /* etat de la porte amont */

INVARIANT

    sas : NIVEAU
    & pav : PORTE
    & pam : PORTE
    & ( pav = ouverte => pam = fermee & sas = bas )
    & ( pam = ouverte => pav = fermee & sas = haut )

INITIALISATION

    sas , pav , pam := haut , fermee , fermee

OPERATIONS

    remplir =
        PRE
            pav = fermee & pam = fermee
        THEN
            sas := haut
        END
    ;
    vider =
        PRE
            pav = fermee & pam = fermee
        THEN
            sas := bas
        END
    ;
    ouvrir_amont =
        PRE
            pav = fermee & pam = fermee & sas = haut
        THEN
            pam := ouverte
        END
    ;
    fermer_amont =
        PRE
            pav = fermee & pam = ouverte & sas = haut
        THEN
            pam := fermee
        END
    ;
    ouvrir_aval =
        PRE
           pav = fermee & pam = fermee & sas = bas
        THEN
            pav := ouverte
        END
    ;
    fermer_aval =
        PRE
            pav = ouverte & pam = fermee & sas = bas
        THEN
            pav := fermee
        END
END
