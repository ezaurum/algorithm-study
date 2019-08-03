;;
;;  하노이탑을 옮기자.
;;

(defn- get-temp-pole [st end]
  (let [xs [1 2 3]
        st-end (set [st end])]
    (first (filter #(not (contains? st-end %)) xs))))

(defn hanoi-tower [n st-pole end-pole]
  (if (= n 1) (println n " -> from:" st-pole "to:" end-pole)
      (do
        (let [temp-pole (get-temp-pole st-pole end-pole)]
          (do
            (hanoi-tower (dec n) st-pole temp-pole)
            (println n " -> from:" st-pole "to:" end-pole)
            (hanoi-tower (dec n) temp-pole end-pole))))))

(hanoi-tower 4 1 3)

;; (get-temp-pole 1 3)
;; (get-temp-pole 2 3)
;; (get-temp-pole 1 2)


;;
;;  https://repl.it/@typeon/chapter-04-hanoi
;;
