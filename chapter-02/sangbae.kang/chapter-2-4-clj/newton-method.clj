;;
(defmacro dbg [x] `(let [x# ~x] (println "dbg:" '~x "=" x#) x#))

;; Examples of dbg
; (println (+ (* 2 3) (dbg (* 8 9))))
; (println (dbg (println "yo")))
; (defn factorial[n] (if (= n 0) 1 (* n (dbg (factorial (dec n))))))
; (factorial 8)

; (def integers (iterate inc 0))
; (def squares  (map #(dbg(* % %))   integers))
; (def cubes    (map #(dbg(* %1 %2)) integers squares))
; (take 5 cubes)
; (take 5 cubes)

(defn fx [x]
  (-> x
      (* x)
      (* x)
      (- x)
      (+ 1)))
(defn gx [x]
  (-> 3
      (* x)
      (* x)
      (- 1)))

(def x -2.0)
(def eps 0.00000001)
(def max-loop 50)

; 뉴턴법으로 방정식 f(x) = 0의 근을 구한다.
;
(loop [k 1
       x -2.0
       break false]
;  (println "k = " k ", x = " x ", break = " break)
  (cond 
    (> k max-loop) (println "수렴하지 않음.")
    (true? break) x
    :else (let [dx x
                newX (- dx (/ (fx x) (gx x)))
                fabs1 (if (> newX dx) (- newX dx) (- dx newX))
                fabs2 (* (if (> dx 0) dx (- 0 dx)) eps)]
            ; (println "dx = " dx ", newX = " newX ", fabs1 = " fabs1 "fabs2 = " fabs2)
            (if (< fabs1 fabs2) newX
                (recur (inc k) newX (< fabs1 fabs2))))))
