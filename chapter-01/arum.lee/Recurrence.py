import math


def ncr(n, r):
    return int((fact(n)) / ((fact(r)) * fact(n - r)))


def fact(n):
    # 이거 쓰려다가 양심에 찔려서..... -_-;;
    # return math.factorial(n)
    res = 1
    for i in range(2, n+1):
        res = res * i
    return res


def triangle(rows):
    result = []
    for count in range(rows):
        row = []
        for element in range(count + 1):
            row.append(ncr(count, element))
        result.append(row)
    return result


for x in range(6):
    for y in range(6):
        if y <= x:
            print(str(x) + "C" + str(y) + " = " + str(ncr(x, y)))


for row in triangle(6):
    print(row)

