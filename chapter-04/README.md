# 연습문제

```
정수 n이 주어지면, n개의 여는 괄호 "("와 n개의 닫는 괄호 ")"로 만들 수 있는 괄호 조합을 모두 구하시오. (시간 복잡도 제한 없습니다).
Given an integer N, find the number of possible balanced parentheses with N opening and closing brackets.

예제)
Input: 1
Output: ["()"]

Input: 2
Output: ["(())", "()()"]

Input: 3
Output: ["((()))", "(()())", "()(())", "(())()", "()()()"]

Input: 4
Output: ["(((())))", "((()()))", "(()(()))", "()((()))", "((())())", "(()()())", "()(()())", "(())(())", "()()(())", "((()))()", "(()())()", "()(())()", "(())()()", "()()()()"]
```

https://repl.it/@typeon/chapter-04-exercise

```
(defn print-parentheses [st l r]
  (if (and (= l 0) (= r 0)) (println "=:" st)
      (if (>= l r)
        (do
            (when (> r 0) (print-parentheses (str ")" st) l (dec r)))
            (when (> l 0) (print-parentheses (str "(" st) (dec l) r))
            ))))

(print-parentheses "" 1 1)
(print-parentheses "" 2 2)
(print-parentheses "" 3 3)
(print-parentheses "" 4 4)
```