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

let lcg = LinearCongruentialGenerator(x0: 8, A: 13, C: 25, M: 128)
for _ in 0...1000 {
    lcg.generate()
}

class LCGTest: XCTestCase {
    var M: Int!
    var lcg: LinearCongruentialGenerator!
    
    override func setUp() {
        super.setUp()
        M = 8192
        lcg = LinearCongruentialGenerator(x0: 8, A: 13, C: 25, M: self.M)
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
}

LCGTest.defaultTestSuite.run()

