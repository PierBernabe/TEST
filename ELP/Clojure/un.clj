;operation basic
(+ 2 2)
(*(+ 1 5) 10)
(-(+ 2 1) (/ (* 3 4 5) 3))

;incremente ++
(inc 1)
;decremente --
(dec 2)

;nommer une valeur
(def a 10)
(+ a 2 a)

;------------------------------------------------------------------------------------
;fn permet de fdefinir une fonction anonyme qui ICI "*" par 2 le param d'entree
(def twice
  (fn [x] (* 2 x)))

(twice a)

;defn fonction nommé
(defn twice [x]
  (* 2 x))

(twice a)

;Une fonction peut supperter différentes "formes"
(defn maximum
  ([x] x )
  ([x y] (if (> x y) x y) ))

(maximum 1)
(maximum 1 2)

;Des arguments variables peuvent se capturer dans une liste avec &
(defn many-args [x y & args]
  (println (str "x=" x))
  (println (str "y=" y))
  (println (str "args=" args)))

(many-args 1 2 3 4 5)

;Fonction Fibonacci récursive if else
(defn fib [n]
  (if (or (= n 0) (= n 1))
    n
    (+ (fib (- n 1)) (fib (- n 2)))
   )
)

(fib 6)

;Fonction Fibonacci récursive cond
(defn fib2 [n]
  (cond
    (or (= n 0) (= n 1)) n
    :else (+ (fib2 (- n 1)) (fib2 (- n 2)))
   )
)

(fib2 7)

;------------------------------------------------------------------------------------
;Les Listes ;cons return a seq and conj a list
(def my-list '(1 2 3 4 5 6))
(cons 100 my-list)
(conj my-list 10)
(conj my-list 20 30 70 77)
(conj my-list '(20 30) '(70 77))
(rest my-list)
(first my-list)
(empty? my-list)
(distinct '(1 2 2 2 2 3))
(take 2 '(1 2 3 4 5))
(count '(1 2 3))

;Toutes ces fonctions ne modifient pas my-list

;------------------------------------------------------------------------------------
;Filter, map, reduce

;filter permet d’exclure des éléments suivant un prédicat
(filter even?
  [1 2 3 4 5 6 7 8 9 10])

;map transforme une collection en appliquant une fonction à chaque élément :
(map
  (fn [x] (+ 10 x))
  '(1 2 3 4))

;Pour des fonctions anonymes courtes, on peut aussi utiliser une forme lambda :
(map
  #(+ 10 %);% est l’unique argument, sinon utilisez %1, …​, %n.
  '(1 2 3 4))


;reduce attend en param une fonction ici + un accumulateur et la liste des prochains éléments
(reduce + 0 '(1 2 3 4 5 6 7 8 9 10))

(reduce #(str %1 %2 " ") "" '("hello" "world" "!"))

;------------------------------------------------------------------------------------
;Composition de fonctions


;apply permet d’appliquer des paramètres à une fonction, ce qui permet de faire des invocations dynamiques
(apply odd? [1])
(apply + [1 2 3])
(apply + '(1 2 3))
(apply + my-list)

;fonction or
(or false false true)


;Soit la fonction either suivante qui compose 2 prédicats pred1 et pred2
;pred1 et pred2 sont des fonctions qui prennent 1 paramètre et retournent un booléen. either renvoie une fonction qui compose ces 2 fonctions avec or
(defn either [pred1 pred2]
  (fn [x] (or
    (apply pred1 [x])
    (apply pred2 [x]) )))




(defn check []
  (let [p1 odd? p2 even?];  let assigne [nom1 valeur1 nom2 valeur2 …]
    (let [always-true (either p1 p2)]
      (println (always-true 1))
      (println (always-true 2)) )))

(check)

;------------------------------------------------------------------------------------
;Sequences "fainéantes" et inifines

(def h (repeat "Hello"))

(take 10 h)
(take 10 (range 0 10000))
(take 10 (range 0 10000 10))

(reduce (fn [acc next] (str acc ">" next "< ")) "" (take 5 h))

;(str h);ATTENTION BOUCLE INIFINI

;tire aleatoirement 10000 element entre 0 et n
(defn random [n] (repeatedly 10000 #(rand-int n)))
(random 10)

(defn moy_random [n]
  (/
    (reduce + 0 (
          take 1000 (repeatedly 10000 #(rand-int n))
    ))
    1000
  )
)

(moy_random 10)

(defn moy_random_paire [n]
  (/
    (reduce + 0 (
          take 1000 (filter even? (repeatedly 10000 #(rand-int n)))  ;replace even by odd pou impaire
    ))
    1000.;le . permet d'avoir le resultat sous forme decimal
  )
)

(moy_random_paire 10)
;------------------------------------------------------------------------------------
;Ex1

(defn compare [n]
   (cond
    (= n \() 1
    (= n \)) -1
    :else 0
  )
)
(defn balanced [n]
  (+ i (compare (first n)))
  (cond
    (empty? n) true
    (< i 0) false
    :else (balanced (rest n))
  )
)

(println (balanced "(test)"))









