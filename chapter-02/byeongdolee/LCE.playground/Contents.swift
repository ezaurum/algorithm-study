import XCTest

//일양난수 제너레이터
class LinearCongruentialGenerator {
    private var value: Int // 이전 값 저장할곳
    private let A: Int // 8로 나누어서 나머지가 5인 수
    private let C: Int // 홀수
    private let M: Int // 2의 배수
    
    init(x0: Int, A: Int, C: Int, M: Int) {
        self.value = x0 // 초기값 설정
        self.A = A
        self.C = C
        self.M = M
    }
    
    func generate() -> Int {
        let result = value
        value = (A * value + C) % M
        return result
    }
}

class LCGTest: XCTestCase {
    var M: Int!
    var lcg: LinearCongruentialGenerator!
    
    override func setUp() {
        super.setUp()
        M = 4096
        lcg = LinearCongruentialGenerator(x0: 13, A: 109, C: 1021, M: self.M)
    }
    
    override func tearDown() {
        super.tearDown()
        M = nil
        lcg = nil
    }
    
    func testValidation() {
        var history = Array<Int>(repeating: -1, count: M)
        for i in 0...M-1 {
            let random = lcg.generate()
            XCTAssertTrue(!history.contains(random))
            history[i] = random
        }
        history
        print("max: \(history.max()!)")
        print("min: \(history.min()!)")
    }
    
    func testChiSquared() {
        
        func rnd() -> Double {
            return Double(lcg.generate()) / (Double(M) - 0.9)
        }
        
        let n = 1000
        let m = 10.0
        let f = n / Int(m) // 기댓값
        var e = 0.0
        
        var data = Array<Int>(repeating: 0, count: Int(m))
        
        for _ in 0..<n {
            let random = Int(rnd() * m)
            data[random] += 1
        }
        
        for i in 0..<data.count {
            var str = "\(i): \(data[i]) "
            for _ in 0..<data[i] {
                str += "*"
            }
            print(str)
            e += Double((data[i] - f) * (data[i] - f)) / Double(f)
        }
        print("χ2: \(e)")
    }
}

LCGTest.defaultTestSuite.run()

