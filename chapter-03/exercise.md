# 연습문제

## 정수 배열에서 연속적인 원소의 합

정수 배열(int array)가 주어지면 가장 큰 이어지는(연속적인) 원소들의 합을 구하시오. 단, 시간복잡도는 O(n).

```
예제}

    Input: [-1, 3, -1, 5]
    Output: 7 // 3 + (-1) + 5

    Input: [-5, -3, -1]
    Output: -1 // -1

    Input: [2, 4, -2, -3, 8]
    Output: 9 // 2 + 4 + (-2) + (-3) + 8

    Input: [10, -20, 10, -5]
    Output: 10
```

```clojure
(defn max-consec-sum
  ([xs] (max-consec-sum (reduce + xs) xs))
  ([sum xs]
    (if (= (count xs) 1) (first xs)
        (max sum
             (max-consec-sum (- sum (first xs)) (rest xs))
             (max-consec-sum (- sum (last xs)) (butlast xs))))))

(max-consec-sum [-1 3 -1 5])
(max-consec-sum [-5 -3 -1])
(max-consec-sum [2 4 -2 -3 8])
(max-consec-sum [10 -20 10 -5])
```

## 피보나치

피보나치 배열은 0과 1로 시작하며, 다음 피보나치 수는 바로 앞의 두 피보나치 수의 합이 된다. 정수 N이 주어지면, N보다 작은 모든 짝수 피보나치 수의 합을 구하여라.

```
예제)

    Input: N = 12
    Output: 10 // 0, 1, 2, 3, 5, 8 중 짝수인 2 + 8 = 10.
```

```clojure
;; 무한 피보나치 수열
(defn fib-seq
  ([] (fib-seq 0 1))
  ([a b] (lazy-seq (cons a (fib-seq b (+' a b))))))

(defn add-even-fib [n]
  (reduce + (filter even? (take n (fib-seq)))))

(take 22 (fib-seq))
(add-even-fib 12)
```
