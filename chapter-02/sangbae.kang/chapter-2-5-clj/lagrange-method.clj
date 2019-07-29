
(def x-vector [0.0 1.0 3.0 6.0 7.0])
(def y-vector [0.8 3.1 4.5 3.9 2.8])
(def max-n 5)

(defn p-f [p t i j]
;   (println i j t (x-vector i) (x-vector j))
  (* p (/ (- t (x-vector j))
          (- (x-vector i) (x-vector j)))))
  

(defn lagrange-sub-element [i t y-i]
  (loop [j 0
         p y-i]
    ; (println i j p (- (x-vector i) (x-vector j)))
    (if (= j max-n) p
      (recur (inc j) 
             (if (= i j) p
               (p-f p t i j))))))

; (println (lagrange-sub-element 0 0.5 (y-vector 0)))

(defn lagrange [t]
  (loop [i 0
         p 0.0]
    (if (= i max-n) p
        (recur (inc i) (+ p (lagrange-sub-element i t (y-vector i)))))))

(loop [t 0.0]
  (when (<= t 7.0) (println t (lagrange t))
        (recur (+ t 0.5))))
