# Examen machine ELP, mai 2017

Les durées et le barème sont donnés à titre indicatif. 

# javascript (20min, 5pts)
Installez node sur votre machine dans /tmp.
``` bash
wget https://nodejs.org/dist/v6.10.0/node-v6.10.0-linux-x64.tar.gz
tar zxvf node-v6.10.0-linux-x64.tar.gz
```
Allez dans le répertoire js et corrigez les codes suivants.
Les codes d'exemples peuvent tous être directement lancés dans l'interpréteur node.
Il faut les modifier pour répondre aux questions.

1) Callbacks
Dans le fichier mesCallbacks.js, commentez les lignes afin d'afficher les fonctions de type callbacks de celles qui ne le sont pas.

2) Fonctionnel
Dans le fichier fonctionnel.js, modifiez le code initial. Ajoutez 2 autres fonctions  qui traitent le tableau en utilisant forEach pour la première fonction et lodash pour la seconde. Pour que lodash fonctionne, pensez à installer le module lodash dans votre interpréteur node.
`npm install lodash`

3) Promesses
installez le module de promesse `fs-extra` dans votre projet
`npm install fs-extra'
31) lancez le script  `promise.js` et corrigez l'erreur du fichier de données.
32) Complétez l'appel à la promesse readJson pour afficher le contenu du fichier de données.

# java (20min, 5pts)
Dans le répertoire java, vous allez travailler avec les fichiers `MyList.java` et `Demo.java`.

1) Conteneurs et flux
Dans le fichier `MyList.java`, complétez les deux méthodes statiques afin d'envoyer le contenu du champs `myList` vers un flux de sortie avec une boucle for étendue, puis avec un itérateur. Ensuite, dans la méthode `main`, appelez indifféremment ces deux méthodes pour afficher la liste sur la sortie standard, l'erreur standard et dans un fichier appelé `pbe.dat`.

2) Classes et interfaces
Observez attentivement le fichier `Demo.java`. Sans modifier la méthode `main` et sachant que les méthodes pbernarbe et ebranrebp affichent seulement un caractère sur la sortie standard, écrivez le code nécessaire pour que l'exécution donne la suite de caractères "abcbc".

# python (20min, 5pts)
Vous allez écrire vos programmes dans le répertoire python. Vous pouvez répondre aux questions par des commentaires. 

* Nous avons la chaîne de caractères suivante : 
  ```python
  >>> spell = 'ebranrebppbernarbe'
  ```
  Essayons de supprimer la sous-chaîne `'pbe'` à l'aide de l'opérateur `del` :
  ```python
  >>> del spell[4:7]
  Traceback (most recent call last):
    File "<pyshell#17>", line 1, in <module>
      del spell[4:7]
  TypeError: 'str' object does not support item deletion
  ```
  Visiblement, ça ne marche pas. Savez-vous pourquoi ? Comment pourrait-on faire alors pour supprimer la sous-chaîne `'pbe'` ?

* On peut parcourir la chaîne `'ebranrebppbernarbe'` dans l'ordre inverse dans une boucle `for` à l'aide de la classe "built-in" `reversed` :
  ```python
  >> for c in reversed(spell):
          print(c, end='')
  ```
  Définissez un générateur, `Reversed`, reproduisant la fonctionnalité de `reversed`. Illustrez comment vous allez vous en servir. Marchera-t-il avec des types de données autres que `str` ? Lesquels ? Pourquoi ?

# clojure (10min, 2.5pts)
Récupérez la dernière version stable de Clojure depuis http://clojure.org. Vous allez écrire votre programme dans le répertoire clojure. 

Avec l'aide des fonctions clojure `filter`, `map`et `reduce`, écrivez une fonction qui prend en entrée une liste de nombres entiers et retourne une chaine formée par les nombres divisible par 3. Chaque nombre devra être entouré des caractères '$' '$' et séparé des autres par ','. 

# go (10min, 2.5pts)
Dans le répertoire `go`, modifiez le code du fichier `generator.go` en complétant la fonction `nombresImpairs`
qui va renvoyer les nombres de la suite demandée à un interval de 300 milliseconds.
Pour la génération de ces nombres vous pouvez vous inspirer du code du fichier `example.go`.
