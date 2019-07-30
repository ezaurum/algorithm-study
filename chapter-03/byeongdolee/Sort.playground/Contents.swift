let arr = [80, 41, 35, 90, 40, 20]

func directSelection(for arr: [Int]) -> [Int] {
    var array = arr
    var minIdx = 0
    
    for j in 0..<array.count-1 {
        for i in j..<array.count {
            if array[i] < array[minIdx] {
                minIdx = i
            }
        }
        let tmp = array[j]
        array[j] = array[minIdx]
        array[minIdx] = tmp
    }
    return array
}

func bubbleSelection(for arr: [Int]) -> [Int] {
    var array = arr
    for i in 1..<array.count {
        
        for j in (i...array.count-1).reversed() {
            let n1 = array[j]
            let n2 = array[j-1]
            if n1 < n2 {
                array[j-1] = n1
                array[j] = n2
            }
        }
    }
    return array
}

func shaker(for arr: [Int]) -> [Int] {
    var array = arr
    var left = 0
    var right = array.count - 1
    var shift = 0
    
    while left < right {
        for i in left..<right {
            if array[i+1] < array[i] {
                let tmp = array[i+1]
                array[i+1] = array[i]
                array[i] = tmp
                shift = i
            }
        }
        right = shift
        
        for i in (left+1...right).reversed() {
            if array[i] < array[i-1] {
                let tmp = array[i]
                array[i] = array[i-1]
                array[i-1] = tmp
                shift = i
            }
        }
        left = shift
    }
    return array
}

shaker(for: arr)

bubbleSelection(for: arr)

directSelection(for: arr)
