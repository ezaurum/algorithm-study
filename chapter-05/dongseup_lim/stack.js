// stack (last in first out)

function Stack() {
    this.dataStore = [];
    this.top = 0;
    this.push = push;
    this.pop = pop;
    this.peek = peek;
    this.clear = clear;
    this.length = length;
}

function push(item) {
    this.dataStore[this.top++] = item;
}

function pop() {
    return this.dataStore[--this.top];
}

function peek() {
    return this.dataStore[this.top - 1];
}

function length () {
    return this.top;
}

function clear() {
    this.top = 0;
}

var s = new Stack();

s.push('스택111');
s.push('스택222');
s.push('스택333');
console.log('length : ' + s.length());
console.log(s.peek());

var popped = s.pop();
console.log('pop item : ' + popped);
console.log(s.peek());
s.push('스택444');
console.log(s.peek());
s.clear();
console.log('length : ' + s.length());
console.log(s.peek());


// 스택을 이용한 진법 변환 알고리즘
function Change(num, base) {
    var s = new Stack();
    do {
        s.push(num % base);
        console.log(num % base)
        num = Math.floor(num = num / base);
    } while(num > 0);

    var converted = '';
    while(s.length() > 0) {
        converted += s.pop();
        //console.log(converted);
    }

    return converted;
}
var num = 13;
var base = 2;
var newNum = Change(num, base);
console.log(num + "를 "+base+"진법으로 변환하면? "+ newNum);





