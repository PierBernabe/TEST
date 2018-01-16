(let [s (new java.util.HashSet)]
  (doto s
    (.add 1)
    (.add 2)
    (.add 3))
  (println (System/currentTimeMillis))
  (println (.contains s 1))
  (println (.contains s 5)) )

