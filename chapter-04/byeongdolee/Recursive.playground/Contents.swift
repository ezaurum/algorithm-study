import Foundation

// FACTORIAL
func factorial(_ n: Int) -> Int {
    if n < 0 {
        fatalError()
    }
    if n == 0 {
       return 1
    }
    return n * factorial(n-1)
}

//for i in 0..<20 {
//    log(Double(factorial(i)))
//}

// FACTORIAL2 (비재귀)
func factorial2(_ n: Int) -> Int {
    var result = 1
    for i in 1...n {
        result *= i
    }
    return result
}

for i in 1..<20 {
    print(factorial(i))
    log(Double(factorial(i)))
}

// FIBONACCI
func fibonacci(_ n: Int) -> Int {
    if n < 0 {
        fatalError()
    }
    if n == 1 || n == 2 {
        return 1
    }
    return fibonacci(n - 1) + fibonacci(n - 2)
}

//for i in 1..<20 {
//    log(Double(fibonacci(i)))
//}

// COMBINATION
func combination(_ n: Int, _ r: Int) -> Int {
    if r < 0 || n < 0 || r > n {
        fatalError()
    }
    if r == 0 || n == r {
        return 1
    }
    return combination(n-1, r-1) + combination(n-1, r)
}

//for n in 0...5 {
//    for r in 0...n {
//        print("\(n)C\(r) = \(combination(n, r))")
//    }
//}

// 유클리드 호제법 (최대공약수 구하기)
func gcd(_ m: Int, _ n: Int) -> Int {
    if m == n {
        return m
    }
    if m - n > 0 {
        return gcd(m-n, n)
    } else {
        return gcd(m, n-m)
    }
}

//gcd(24, 18)
//gcd(128, 72)

// 유클리드 호제법2 (최대공약수 구하기)
func gcd2(_ m: Int, _ n: Int) -> Int {
    if n == 0 {
        return m
    }
    return gcd2(n, m % n)
}

gcd(24, 18)
gcd(128, 72)





