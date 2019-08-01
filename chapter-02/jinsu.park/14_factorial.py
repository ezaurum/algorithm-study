def factorialBase(n):
    result = 1
    for i in range(n, 0, -1):
        result *= i
        print(i, end=" ")
        print("")
        print(result, end=" ")


def factorialRecursive(n):
    if (n == 0 or n == 1):
        return 1;
    return n * factorialRecursive(n - 1)


factorialBase(5)

factorialRecursive(5)
