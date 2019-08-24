class Node<Element> {
    var left: Int?
    let data: Element
    var right: Int?
    
    init(_ left: Int?, _ data: Element, _ right: Int?) {
        self.left = left
        self.data = data
        self.right = right
    }
}

var arr = [Node<String>(1, "Matilda", 2), Node<String>(3, "Candy", 4), Node<String>(5, "Rolla", nil)
    ,Node<String>(nil, "Ann", nil), Node<String>(6, "Emy", 7), Node<String>(nil, "Nancy", nil)
    ,Node<String>(nil, "Eluza", nil), Node<String>(nil, "Lisa", nil)]

func search(for key: String) -> String {
    var node = arr[0]
    
    while true {
        if node.data == key {
            return "GOOOOOD!"
        }
        
        if node.data > key {
            guard let left = node.left else { return "not found" }
            node = arr[left]
        } else {
            guard let right = node.right else { return "not found" }
            node = arr[right]
        }
    }
}

func insert(_ key: String) {
    var node = arr[0]
    
    while true {
        if node.data == key {
            return
        }
        
        if node.data > key {
            guard let left = node.left else {
                node.left = arr.count
                arr.append(Node<String>(nil, key, nil))
                return
            }
            
            node = arr[left]
        } else {
            guard let right = node.right else {
                node.right = arr.count
                arr.append(Node<String>(nil, key, nil))
                return
            }
            node = arr[right]
        }
    }
}

//
//search(for: "Matilda")
//search(for: "fuck")
//search(for: "Candy")
//search(for: "Nancy")
//
//search(for: "Byeongdolee")
//insert("Byeongdolee")
//insert("Byeongdolee2")
//insert("Byeongdolee3")
//insert("Byeongdolee4")
//insert("Byeongdolee5")
//insert("fuck")
//search(for: "Byeongdolee2")
//search(for: "fuck")
//arr

class NodeLinkVersion<Element> {
    var left: NodeLinkVersion?
    let data: Element
    var right: NodeLinkVersion?
    
    init(_ left: NodeLinkVersion?, _ data: Element, _ right: NodeLinkVersion?) {
        self.left = left
        self.data = data
        self.right = right
    }
}

var root: NodeLinkVersion<String>? = nil

func searchLinkV(for key: String) -> String {
    var node = root
    
    if node == nil {
        return "not found"
    }
    
    while true {
        if node!.data == key {
            return "GOOOOOD!"
        }
        
        if node!.data > key {
            guard let left = node!.left else { return "not found" }
            node = left
        } else {
            guard let right = node!.right else { return "not found" }
            node = right
        }
    }
}

func insertLinkV(_ key: String) {
    var node = root
    
    if node == nil {
        root = NodeLinkVersion<String>(nil, key, nil)
        return
    }
    
    while true {
        if node!.data == key {
            return
        }
        
        if node!.data > key {
            guard let left = node!.left else {
                node!.left = NodeLinkVersion<String>(nil, key, nil)
                return
            }
            
            node = left
        } else {
            guard let right = node!.right else {
                node!.right = NodeLinkVersion<String>(nil, key, nil)
                return
            }
            node = right
        }
    }
}

//searchLinkV(for: "hello")
//searchLinkV(for: "fuck")
//
//insertLinkV("hello")
//insertLinkV("fuck")
//
//searchLinkV(for: "hello")
//searchLinkV(for: "fuck")
//
//searchLinkV(for: "Byeongdolee")
//insertLinkV("Byeongdolee")
//insertLinkV("Byeongdolee2")
//insertLinkV("Byeongdolee3")
//insertLinkV("Byeongdolee4")
//insertLinkV("Byeongdolee5")
//
//searchLinkV(for: "Byeongdolee")
//searchLinkV(for: "Byeongdolee2")
//searchLinkV(for: "Byeongdolee3")
//searchLinkV(for: "Byeongdolee4")
//searchLinkV(for: "Byeongdolee5")


func gentree(_ node: NodeLinkVersion<String>?, _ key: String) -> NodeLinkVersion<String> {
    if node == nil {
        return NodeLinkVersion<String>(nil, key, nil)
    }
    
    // 있으면 걍 리턴
    if node!.data == key {
        return node!
    }
    
    if key < node!.data {
        node!.left = gentree(node!.left, key)
    } else {
        node!.right = gentree(node!.right, key)
    }
    return node!
}

func searchRecursive(_ node: NodeLinkVersion<String>?, _ key: String) -> String {
    guard let n = node else { return "not found" }
    
    if n.data == key {
        return "FOUND!!"
    }
    
    if key < n.data {
        return searchRecursive(n.left, key)
    } else {
        return searchRecursive(n.right, key)
    }
}


root = gentree(root, "50")
root = gentree(root, "35")
root = gentree(root, "25")
root = gentree(root, "40")
root = gentree(root, "36")
root = gentree(root, "41")
root = gentree(root, "60")


func treewalk1(_ node: NodeLinkVersion<String>?) {
    guard let n = node else { return }
    print(n.data)
    treewalk1(n.left)
    treewalk1(n.right)
}


func treewalk2(_ node: NodeLinkVersion<String>?) {
    guard let n = node else { return }
    treewalk2(n.left)
    print(n.data)
    treewalk2(n.right)
}

func treewalk3(_ node: NodeLinkVersion<String>?) {
    guard let n = node else { return }
    treewalk3(n.left)
    treewalk3(n.right)
    print(n.data)
}

func treewalkDesc(_ node: NodeLinkVersion<String>?) {
    guard let n = node else { return }
    treewalkDesc(n.right)
    print(n.data)
    treewalkDesc(n.left)
}

// treewalkDesc(root)

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

var stack = Stack<NodeLinkVersion<String>>()

// 왜 팝 하고나서 프린트 하는지 궁금했는데... 해보고 나니 이게 더 심플하네..
func treewalkStack() {
    var node = root
    
    while node != nil || stack.size != 0 {
        while node != nil {
            stack.push(newElement: node!)
            node = node!.left
        }
        node = stack.pop()
        print(node!.data)
        node = node!.right
    }
}

treewalkStack()



