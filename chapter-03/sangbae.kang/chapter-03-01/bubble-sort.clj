;; 추가할 값을 insert할 위치로 이동시킴.
;;
(defn- bubble [ys x]
  (if-let [y (peek ys)]
    (if (> y x)
        (conj (pop ys) x y)
        (conj ys x))
    [x]))
  
(defn bubble-sort [xs]
  (let [ys (reduce bubble [] xs)]
    (if (= xs ys)
      xs
      (recur ys))))

(def coll [80 41 35 90 40 20])
(time (bubble-sort coll))
