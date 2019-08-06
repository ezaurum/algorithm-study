import Foundation

var arr = [45,73,12,44,32,94,78,39,29,56,22,1,6,2]
func quickSort(_ left: Int, _ right: Int) -> [Int] {
    let leftValue = arr[left]
    if left < right {
        var i = left + 1
        var j = right
        while true {
            while arr[i] < leftValue { i += 1 }
            while arr[j] > leftValue { j -= 1 }
            if i >= j {
                break
            }
            
            let tmp = arr[i]
            arr[i] = arr[j]
            arr[j] = tmp
            print(arr)
        }
        arr[left] = arr[j]
        arr[j] = leftValue
        quickSort(left, j - 1)
        quickSort(j + 1, right)
    }
    
    return arr
}

print(quickSort(0, arr.count - 1))

func hanoi(_ n: Int, _ a: String, _ b: String, _ c: String) {
    if n > 0 {
        hanoi(n - 1, a, c, b)
        print("\(n)번 원반을 \(a)에서 \(b)로 이동")
        hanoi(n - 1, c, b, a)
    }
}

hanoi(5, "a", "b", "c")

//P1
//겉에 감싸기(1) + 앞, 뒤 낱개로 추가(2), 맨 마지막 낱개는 앞 뒤 추가하는게 중복임
// f(1) = 1
// f(x) = 3 * f(x-1) - 1
func parentheses(_ n: Int) -> [String] {
    if n < 0 {
        fatalError()
    }
    
    if n == 0 {
        return []
    }
    
    if n == 1 {
        return ["()"]
    }
    
    let arr = parentheses(n - 1)
    var result = [String]()
    
    for i in 0..<arr.count {
        result.append("(\(arr[i]))")
        
        let pre = "()\(arr[i])"
        let post = "\(arr[i])()"
        result.append(pre)
        if pre != post {
            result.append(post)
        }
    }
    
    return result
}

for i in 1...5 {
    let result = parentheses(i)
    print(result)
    print(result.count)
}


let max = 4

var arr = Array<Int>(1...max)
//PERMUTATION
func permutation(_ n: Int) {
    
    if n < max - 1 {
        for i in n..<max {
            let tmp = arr[i]
            arr[i] = arr[n]
            arr[n] = tmp
            permutation(n+1)
            arr[n] = arr[i]
            arr[i] = tmp
        }
    } else {
        print(arr)
    }
}

permutation(0)

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

//for i in 1..<20 {
//    print(factorial(i))
//    log(Double(factorial(i)))
//}

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

//gcd(24, 18)
//gcd(128, 72)





