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
      
(def coll [80 41 35 90 40 20])
(time (bubble-sort coll))
