(defn- bubble
  ([xs] (bubble xs [] false))
  ([[x y & xs] ys changed]
   (if (nil? y)
      [(conj ys x) changed]
      (if (> x y)
          (recur (cons x xs) (conj ys y) true)
          (recur (cons y xs) (conj ys x) changed)))))

(defn bubble-sort [xs]
  (loop [[ys changed] (bubble xs)]
    (if changed
      (recur (bubble ys))
      ys)))


;; 다른 버전 3
;;
(defn bubble-sort2
  ([xs] (loop [x xs j (count xs)]
          (if (> j 0) 
              (recur (bubble-sort2 x 0 j) (- j 1))
              x)))

  ([xs i j] (if (< (+ i 1) j)
                (let [x (xs i) y (xs (+ i 1))]
                  (recur (if (> x y) (assoc (assoc xs (+ i 1) x) i y) xs) 
                         (+ 1 i) j))
                xs)))

(def coll [80 41 35 90 40 20])
(time (bubble-sort2 coll))
(time (bubble-sort coll))
