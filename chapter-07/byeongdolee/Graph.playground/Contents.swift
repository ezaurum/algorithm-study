let data = [
    [0,0,0,0,0,0,0,0,0],
    [0,0,1,0,0,0,0,0,0],
    [0,1,0,1,1,0,0,0,0],
    [0,0,1,0,0,0,0,1,0],
    [0,0,1,0,0,1,0,0,0],
    [0,0,0,0,1,0,1,0,0],
    [0,0,0,0,0,1,0,1,1],
    [0,0,0,1,0,0,1,0,1],
    [0,0,0,0,0,0,1,1,0],
]

var visited = [Int](repeating: 0, count: 9)
visited[0] = 1

// 깊이 우선 탐색
func depthFirstSearch() {

    for k in 1..<9 {
        var i = k
        for index in visited.indices {
            visited[index] = 0
        }
        visited[0] = 1
        print("==================")
        while i < 9 {
            visited[i] = 1
            let nodeData = data[i]
            var changed = false
            for (index, element) in nodeData.enumerated() {
                if visited[index] == 1 {
                    continue
                }
                
                if element == 0 {
                    continue
                }
                
                changed = true
                print("\(i) -> \(index)")
                i = index
                break
            }
            
            if !changed {
                guard let notVisitedIndex = visited.firstIndex(of: 0) else {
                    break
                }
                
                var from = -1
                
                for j in 1..<9 {
                    let d = data[j]
                    if d[notVisitedIndex] == 1 {
                        from = j
                        break
                    }
                }
                
                if from != -1 {
                    print("\(from) -> \(notVisitedIndex)")
                    i = notVisitedIndex
                } else {
                    break
                }
            }
        }
    }
}



//depthFirstSearch()

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

let data2 = [
    [0,0,0,0,0,0,0,0,0],
    [0,0,1,0,0,0,0,0,0],
    [0,1,0,1,1,1,0,0,0],
    [0,0,1,0,0,0,0,1,0],
    [0,0,1,0,0,0,0,0,0],
    [0,0,1,0,0,0,1,0,0],
    [0,0,0,0,0,1,0,1,1],
    [0,0,0,1,0,0,1,0,1],
    [0,0,0,0,0,0,1,1,0],
]

func breadthFirstSearch() {
    
    let queue = Queue<Int>()
    visited[0] = 1
    queue.queueIn(newElement: 1)
    while true {
        if queue.size == 0 {
            return
        }
        let current = queue.queueOut()
        visited[current] = 1
        
        let d = data2[current]
        
        for j in d.indices {
            if visited[j] == 0, d[j] == 1 {
                print("\(current) -> \(j)")
                visited[j] = 1
                queue.queueIn(newElement: j)
            }
        }
    }
}

breadthFirstSearch()
