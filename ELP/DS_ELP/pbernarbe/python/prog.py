spell = 'ebranrebppbernarbe'

del spell[4:7]
#dir(spell) permet d'afficher les fonctions défini pour notre objet et l'on remarque que del ne l'ait pas pour spell

#On peut utliser la fonction replace qui va chercher la sous chaine pbe
#puis la remplacer par rien
spell.replace('pbe',"")

#generateur reproduissant la fonctionnalité reversed
generateur = (v for v in spell[0:])
for element in generateur:
    print(element)

#ça marchera aussi avec les sequences