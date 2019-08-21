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
//let queue = Queue<Int>()
//for i in 0...100 {
//    queue.queueIn(newElement: i)
//}
//
//for _ in 0...100 {
//    print(queue.queueOut())
//}


class NamedElement {
    var name: String
    
    init(_ name: String) {
        self.name = name
    }
}

// 리스트
class Profile: NamedElement, CustomStringConvertible {
    var tel: String
    var description: String {
        return "name: \(name), tel: \(tel)"
    }
    
    init(_ name: String, _ tel: String) {
        self.tel = tel
        super.init(name)
    }
}



class Node<NamedElement> {
    var data: NamedElement?
    var pointer: Node<NamedElement>?
    
    init() {
        
    }
    
    init(_ data: NamedElement) {
        self.data = data
    }
    
    init(_ data: NamedElement, _ next: Node<NamedElement>) {
        self.data = data
        self.pointer = next
    }
}


class List<Element> {
    var head = Node<NamedElement>()
    
    func add(newElement element: NamedElement) {
        if head.pointer != nil {
            var n = head.pointer!
            while n.pointer != nil {
                n = n.pointer!
            }
            n.pointer = Node<NamedElement>(element)
        } else {
            head.pointer = Node<NamedElement>(element)
        }
        
    }
    
    func display() {
        guard let hp = head.pointer else { return }
        
        var p: Node<NamedElement>? = hp
        while p != nil {
            print(p?.data ?? "no data")
            p = p?.pointer
        }
    }
    
    func find(by name: String) -> NamedElement? {
        var p = head.pointer
        var old: Node<NamedElement>? = nil
        while p != nil {
            if p!.data?.name == name {
                old?.pointer = p?.pointer
                p?.pointer = head.pointer
                head.pointer = p
                return p!.data!
            }
            old = p
            p = p!.pointer
        }
        
        return nil
    }
}



var list = List<Profile>()

for i in 0...10 {
    let profile = Profile("name\(i)", "tel\(i)")
    list.add(newElement: profile)
}
//
//list.display()
//print("-------------------")
//list.find(by: "name5")
//list.find(by: "hello")
//list.find(by: "name10")
//list.display()

class Hash {
    private var array = [Node<NamedElement>?](repeating: nil, count: 1000)
    
    func search(by name: String) -> NamedElement? {
        var hash = name.hashValue % 1000
        if hash < 0 {
            hash *= -1
        }
        var node = array[hash]
        
        while node != nil {
            if node?.data?.name == name {
                return node!.data!
            }
            node = node?.pointer
        }
        return nil
    }
    
    func add(newElement element: NamedElement) {
        var hash = element.name.hashValue % 1000
        if hash < 0 {
            hash *= -1
        }
        var node = array[hash]
        if node == nil {
            array[hash] = Node<NamedElement>(element)
            return
        }
        
        while node?.pointer != nil {
            node = node?.pointer
        }
        
        node?.pointer = Node<NamedElement>(element)
    }
    
}

let hash = Hash()
hash.add(newElement: Profile("병도리", "010-6649-6321"))
hash.add(newElement: Profile("방구", "1234"))
hash.add(newElement: Profile("메롱", "5678"))

hash.search(by: "병도리")
hash.search(by: "방구")
