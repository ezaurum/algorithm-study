# 연습문제

## 합의 요소 2개 찾기

```
정수 배열과 타겟 숫자가 주어지면, 합이 타겟값이 되는 두 원소의 인덱스를 찾으시오.
단, 시간복잡도 O(n) 여야 합니다.

예제)
Input: [2, 5, 6, 1, 10], 타겟 8
Output: [0, 2] // 배열[0] + 배열[2] = 8

Input: [2, 5, 6, 1, 10], 타겟 11
Output: [1, 2, 3, 4] 또는 에러 메시지
```

## Roman Numerals Decoder

Create a function that takes a Roman numeral as its argument and returns its value as a numeric decimal integer. You don't need to validate the form of the Roman numeral.
Modern Roman numerals are written by expressing each decimal digit of the number to be encoded separately, starting with the leftmost digit and skipping any 0s. So 1990 is rendered "MCMXC" (1000 = M, 900 = CM, 90 = XC) and 2008 is rendered "MMVIII" (2000 = MM, 8 = VIII). The Roman numeral for 1666, "MDCLXVI", uses each letter in descending order.

```
Example:
    solution('XXI') # should return 21
Help:
    Symbol    Value
    I          1
    V          5
    X          10
    L          50
    C          100
    D          500
    M          1,000
```

