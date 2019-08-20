// queue (first in first out)

function Queue() {
    this.arr = [];
}

Queue.prototype.enqueue = function(item) {
    this.arr.push(item)
};

Queue.prototype.dequeue = function(item) {
    return this.arr.shift();
};

var qu = new Queue();

qu.enqueue(1);
qu.enqueue(2);
qu.enqueue(3);
console.log(qu.dequeue());
