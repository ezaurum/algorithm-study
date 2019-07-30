    
(defn binary-search 
    ([k coll] (binary-search 0 (dec (count coll)) k coll))

    ([st end k coll]
     (if (> st end) -1
        (let [middle (quot (+ st end) 2)
              val (get coll middle)]
            (cond
                (= k val) middle
                (> k val) (binary-search (inc middle) end k coll)
                :else (binary-search st (dec middle) k coll))))))


(def coll [1 2 3 4 5 6 7 8 9 10])
(binary-search 1 coll)
