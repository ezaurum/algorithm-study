// STACK
class Stack<Element> {
    private var array = Array<Element?>(repeating: nil, count: 16)
    private var pointer: Int = 0
    var size: Int {
        return pointer
    }
    
    func push(newElement element: Element) {
        if array.count == pointer {
            array.append(contentsOf: repeatElement(nil, count: array.count)) // 사이즈 2배로 늘림
        }
        array[pointer] = element
        pointer += 1
    }
    
    func pop() -> Element {
        pointer -= 1
        guard let ele = array[pointer] else { fatalError() }
        return ele
    }
}

let stack = Stack<Int>()
for i in 0...100 {
    stack.push(newElement: i)
    print(stack.size)
}

for _ in 0...100 {
    print(stack.pop())
}


