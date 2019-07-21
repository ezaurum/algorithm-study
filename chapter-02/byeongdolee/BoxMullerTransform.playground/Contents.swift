import Foundation

class BoxMullerRandomNumberGenerator {
    let sig: Double
    let m: Double
    
    init(sig: Double, m: Double) {
        self.sig = sig
        self.m  = m
    }
    
    func generate() -> Int {
        let r1 = Double.random(in: 0..<1)
        let r2 = Double.random(in: 0..<1)
        return Int(sig * sqrt(-2 * (log(r1))) * cos(2 * Double.pi * r2) + m)
    }
}

let m = 10.0
let sig = 2.5
let bmg = BoxMullerRandomNumberGenerator(sig: sig, m: m)

var arr = [Int](repeating: 0, count: Int(bmg.m) * 10)
for _ in 0...50000 {
    let random = bmg.generate()
    arr[Int(random)] += 1
}

for i in 0...20 {
    var str = "\(i): I "
    for _ in 0..<arr[i]/100 {
        str += "*"
    }
    print(str)
}

