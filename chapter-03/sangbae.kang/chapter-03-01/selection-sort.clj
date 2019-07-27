;; 배열에서 특정 위치의 값을 제거함.
(defn remove-nth [n coll]
    (concat (take n coll) (drop (inc n) coll)))
  
(defn internal-indexed-array [n coll]
    (if (empty? coll) nil
        (cons [n (first coll)] (internal-indexed-array (inc n) (rest coll)))))

;; (map-indexed vector coll) - collection을 배열로 변환.
(defn indexed-array [coll]
  (internal-indexed-array 0 coll))
  
;; 배열에서 제일 작은 값과 index를 구함.
(defn min-value [coll]
  (apply min-key second (indexed-array coll)))
  
;; 
(defn selection-sort [coll]
  (if (empty? coll) coll
      (cons (second (min-value coll))
            (selection-sort (remove-nth (first (min-value coll)) coll)))))
  
(def coll [80 41 35 90 40 20])
  
(time (selection-sort coll))
  