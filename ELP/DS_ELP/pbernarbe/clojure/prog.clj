(def mylist '[1 2 3 4 5 6])

(defn div3 [input-no] (zero? (mod input-no 3)))


(reduce #(str %1 "$" %2 "$,") "" (filter div3 mylist))