package chapter05;

public class MyQueue {
    private char[] queue;   // 큐
    private int head;       // head 포인터
    private int tail;       // tail 포인터

    public MyQueue(int size) {
        this.queue = new char[size];
        this.head = 0;
        this.tail = 0;
    }

    public void enqueue(char c) {
        queue[tail++] = c;
    }

    public char dequeue() {
        return queue[head++];
    }

}
