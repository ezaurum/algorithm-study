(defn merge2 [xs ys]
  (cond
      (empty? xs) ys
      (empty? ys) xs
      :else (let [f-xs (first xs) f-ys (first ys)]
                 (if (< f-xs f-ys) (cons f-xs (merge (rest xs) ys))
                     (cons f-ys (merge xs (rest ys)))))))


(println (merge2 [1 3] [2 4 6]))
(println (merge2 [1 3 5 15 21] [2 10 20]))
(println (merge2 [1 3 5 15] [2 10 20]))
(println (merge2 [1 3 5] [2 2 3]))
(println (merge2 [2 4 5 7 8 10 15 20 30 40 45 50 60] [6 11 25 33 35]))
