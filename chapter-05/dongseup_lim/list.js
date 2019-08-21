// 목ㄹ록 순서가 있는 일련의 집합체
// 리스트 데이터 항목을 요소,
// 빈틈없는 데이터 적재의 장점을 취한 자료구조

// 리스트 추상화
var List = function() {
    this.dataStore = [];
    this.pop = 0; // 현재 위치
    this.listSize = 0; // 리스트 요소 수
}

// append (리스트 마지막 요소 다음 순서에 추가 - 크기 늘리기)
List.prototype.append = function(element) {
    this.dataStore[this.listSize] = element;
    this.listSize++;
}

// find 특정  값이 리스트에 포함되어있는지... 있다면 위지(position)을 리턴 없으면 -1 리턴
List.prototype.find = function(element) {
    for(var i = 0; i < this.listSize; i++) {
        if(this.dataStore[i] === element) {
            return i
        }
    }
    return -1
}

// remove (특정 값을 찾고 요소를 삭제하고 당긴후 빈틈없는 데이터 적제)
List.prototype.remove = function(element) {
    var removePos = this.find(element);

    if (removePos > -1) {
        this.dataStore.splice(removePos, 1);
        this.listSize--;
        return true;
    }
    return false;
}

// length (리스트에 저장된 요소의 갯수)
List.prototype.length = function() {
    return this.listSize;
}

// toString (리스트 요소 확인)
List.prototype.toString = function() {
    return this.dataStore;
}

// insert (기존 리스트 뒤에 추가하기)
List.prototype.insert = function(element, after) {
    var insertPos = this.find(after);
    if(insertPos > -1) {
        this.dataStore.splice(insertPos+1, 0, element);
        this.listSize++;
        return true;
    }
    return false;
}

// clear ( 리스트 모든 요소 제거)
List.prototype.clear = function() {
    this.dataStore = [];
    this.listSize = 0;
    this.pos = 0;
}

// front (탐색위치를 맨 앞으로)
List.prototype.front = function() {
    this.pos = 0;   
}

// end (탐색위치를 맨 뒤로)
List.prototype.end = function() {
    this.pos = this.listSize - 1;
}

// prev (현재 탐색위치보다 이전)
List.prototype.prev = function() {
    if(this.pos > 0) {
        this.pos--;
    }
}

// next (현재 탐색위치보다 이후)
List.prototype.next = function() {
    if(this.pos < this.listSize - 1) {
        this.pos++
    }
}

// currentpos (현재위치)
List.prototype.currPos = function() {
    return this.pos;
}

// moveTo (위치이동)
List.prototype.moveTo = function(position) {
    if(position < this.listSize){
        this.pos = position;
    }
}

// getelement (현재 탐색위치 요소 리턴받기)
List.prototype.getElement = function() {
    return this.dataStore[this.pos];
}


var li = new List();

li.append(1);
li.append(2);
li.append(3);
li.append(4);
li.append(5);

console.log(li.find(3))

console.log(li.remove(4))
console.log(li.toString())
console.log(li.length)

console.log(li.insert(100, 2))
console.log(li.toString())

li.end();
console.log(li.getElement())

li.moveTo(3);
console.log(li.getElement())