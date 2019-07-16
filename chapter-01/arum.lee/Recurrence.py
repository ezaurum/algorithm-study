# Binomial Coefficients 를 어떻게 줄일지 고민하다가 nCr로 바꿈....


def ncr(n, r):
    return factorial(n) / (factorial(r) * factorial(n - r))


def factorial(n):
    res = 1
    for i in range(2, n+1):
        res = res * i
    return res


for x in range(6):
    for y in range(6):
        if y <= x:
            print(str(x) + "C" + str(y) + " = " + str(int(ncr(x, y))))
