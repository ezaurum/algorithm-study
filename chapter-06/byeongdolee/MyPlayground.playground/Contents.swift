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


search(for: "Matilda")
search(for: "fuck")
search(for: "Candy")
search(for: "Nancy")

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

search(for: "Byeongdolee")
insert("Byeongdolee")
insert("Byeongdolee2")
insert("Byeongdolee3")
insert("Byeongdolee4")
insert("Byeongdolee5")
insert("fuck")
search(for: "Byeongdolee2")
search(for: "fuck")
arr

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


searchLinkV(for: "hello")
searchLinkV(for: "fuck")

insertLinkV("hello")
insertLinkV("fuck")

searchLinkV(for: "hello")
searchLinkV(for: "fuck")

searchLinkV(for: "Byeongdolee")
insertLinkV("Byeongdolee")
insertLinkV("Byeongdolee2")
insertLinkV("Byeongdolee3")
insertLinkV("Byeongdolee4")
insertLinkV("Byeongdolee5")

searchLinkV(for: "Byeongdolee")
searchLinkV(for: "Byeongdolee2")
searchLinkV(for: "Byeongdolee3")
searchLinkV(for: "Byeongdolee4")
searchLinkV(for: "Byeongdolee5")

