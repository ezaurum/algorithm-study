
func y(at x: Double) -> Double {
    return x * x
}

let start = 0.0
let end = 10.0
let size = 5000
let h = (end - start) / Double(size)

var result = 0.0
for i in 1..<size {
    result += y(at: start + (Double(i) * h))
}

result = (result + ((y(at: start) + y(at: end)) / 2.0)) * h
result
