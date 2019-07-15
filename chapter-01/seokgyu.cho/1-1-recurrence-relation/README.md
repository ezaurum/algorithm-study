#Chapter 1

## 점화식
자기 자신을 이웃하는 항과 특정값으로 정의하는 0차로 표현한 식

### 예제
n 개 중 r개를 선택하는 조합을 nCr 로 표기
공식은 n! / (r!(n-r)!) = nPr / r!
순열 nPr 을 r!로 나눈 값과 동일

nPr을 점화식으로 표현하려면

nPr = nPr-1 * x
n! / (n-r)! = n! / (n-(r-1))! *x
x = (n - r +1) *  (n-r)! / (n-r)! 
x = (n -r +1)
즉
nPr = nPr-1 * (n-r+1)

같은 식으로, 

nCr = nPr / r!
nCr-1 = nPr-1 / (r-1)! = r * nPr-1 / r! = r * nPr / (n-r+1) / r! = nPr / r! * (r / (n-r+1)) = nCr  * r /(n-r+1)

그러므로 
nCr = nCr-1 * (n-r+1) / r

```
go run main.go
```

