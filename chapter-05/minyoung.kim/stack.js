
function Stack() {
    this.dataStore = []; // 스택 요소 저장
    this.top = 0; // 스택의 최상단 index 저장
    this.push = push;
    this.pop = pop;
    this.peek = peek;
    this.clear = clear;
    this.length = length;
}

function push(element) {
    console.log(element);
    console.log('1. this.top: ' + this.top);
    this.dataStore[this.top++] = element;
    console.log('2. this.top: ' + this.top);
    console.log('this.dataStore: ' + this.dataStore);
}

function pop() {
    console.log('3. this.top: ' + this.top);
    return this.dataStore[--this.top];
}

function peek() {
    return this.dataStore[this.top -1];
}

function clear() {
    this.top = 0;
}

function length() {
    return this.top;
}

/**
 * 스택을 이용한 팩토리얼 구현
 */
function factorial(n) {
    const stack = new Stack();
    while (n > 1) {
        console.log('input => ' + n);
        stack.push(n--);
    }

    let result = 1;
    while (stack.length() > 0) {
        result *= stack.pop();
    }

    return '결과 => ' + result;
}
console.log(factorial(5));