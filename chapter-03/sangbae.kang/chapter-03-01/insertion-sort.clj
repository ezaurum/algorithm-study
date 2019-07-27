;; insert할 위치를 찾아서 추가하도록 작성.
;; 
(defn insert-sorted
    [values n]
    (let [partitioned (split-with (partial > n) values)]
        (into (vec (first partitioned)) (cons n (second partitioned)))))
        
(defn insertion-sort [coll]           
    (seq (reduce insert-sorted [] coll)))


(def coll [80 41 35 90 40 20])  
(time (insertion-sort coll))
