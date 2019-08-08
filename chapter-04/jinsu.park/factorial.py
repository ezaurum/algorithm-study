import temp as temp


def factorial(n):
    if n == 0:
        return 1
    return n * factorial(n - 1)


print(factorial(5))


def factorial02(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)


for i in range(0, 13):
    temp = ""
    for j in range(13-i):
        temp += ' '
    print(str(i) + '!=' + str(temp) + str(factorial02(i)) )
