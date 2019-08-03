;;
;; 4-2 호너법
;;
(def xs [1 2 3 4 5])

(defn polynomial [x xs]
  (if (empty? xs) 0
      (+ (first xs) (* x (polynomial x (rest xs))))))

(polynomial 2 xs)

;;
;; 최대공약수
;;
(defn gcd [m n]
  (cond
    (= m n) m
    (> m n) (gcd (- m n) n)
    :else (gcd m (- n m))))

(gcd 3 2)
(gcd 24 18)
(gcd 128 72)

;;
;; 최대공약수2
;;
(defn gcd2 [m n]
  (if (= n 0) m
      (if (= m n) m
          (recur n (mod m n)))))

(gcd2 14 32)
(gcd2 32 14)
(gcd2 128 72)

;;
;; 4.3 permutation
;;
(defn swap [xs i j]
  (if (= i j) xs
      (let [xs-i (get xs i)
            xs-j (get xs j)]
        (assoc (assoc xs i xs-j) j xs-i))))

(defn permutation [xs i]
  (when (= i (count xs)) (println "permutation: " xs i))
  (loop [j i]
    (if (= j (count xs)) xs
        (do
          (permutation (swap xs i j) (inc i))
          (recur (inc j))))))

(permutation [1 2 3] 0)
(permutation [1 2 3 4] 0)

;;
;; lexical-permutation
;;
(defn rotate-swap [xs i j]
  (let [f-xs (take i xs)
        e-xs (drop (inc j) xs)
        i-j-xs (subvec (vec xs) i (inc j))]
      ;; (println "i-j-xs" i-j-xs)
      ;; (println "rotate-i-j-xs" (cons (last i-j-xs) (butlast i-j-xs)))
    (concat f-xs (cons (last i-j-xs) (butlast i-j-xs)) e-xs)))

(defn lexical-permutation [xs i]
  (when (= i (count xs)) (println "permutation: " xs i))
  (loop [j i]
    (if (= j (count xs)) xs
        (do
          (lexical-permutation (rotate-swap xs i j) (inc i))
          (recur (inc j))))))

(permutation [1 2 3] 0)
(permutation [1 2 3 4] 0)
(lexical-permutation [1 2 3] 0)
(lexical-permutation [1 2 3 4] 0)

