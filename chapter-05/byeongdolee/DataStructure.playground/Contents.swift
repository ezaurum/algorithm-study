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
        array[pointer] = nil
        return ele
    }
}

//let stack = Stack<Int>()
//for i in 0...100 {
//    stack.push(newElement: i)
//    print(stack.size)
//}
//
//for _ in 0...100 {
//    print(stack.pop())
//}

// Queue
// 책과 다르게 사이즈 한정짓지 않았는데...
// 이렇게 할 경우 어레이 앞쪽에 쌓이는 null들을 언젠가 없애버리는 로직이 필요해보임..
class Queue<Element> {
    private var array = Array<Element?>(repeating: nil, count: 16)
    private var head: Int = 0
    private var tail: Int = 0
    var size: Int {
        return tail - head
    }
    
    func queueIn(newElement element: Element) {
        if array.count == tail {
            array.append(contentsOf: repeatElement(nil, count: array.count)) // 사이즈 2배로 늘림
        }
        array[tail] = element
        tail += 1
    }
    
    func queueOut() -> Element {
        guard let ele = array[head] else { fatalError() }
        array[head] = nil
        head += 1
        return ele
    }
}

// 위의 스택과는 다르게 들어간 순서대로 출력됨
let queue = Queue<Int>()
for i in 0...100 {
    queue.queueIn(newElement: i)
}

for _ in 0...100 {
    print(queue.queueOut())
}

queue


