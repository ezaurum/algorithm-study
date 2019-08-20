package chapter05;

public class MyStack {
    private char[] stack;   // 스택
    private int sp;         // 스택포인터

    public MyStack(int size) {
        this.stack = new char[size];
        this.sp = 0;
    }

    public void push(char c) {
        stack[sp++] = c;
    }

    public char pop() {
        if (sp > 0) {
            return stack[--sp];
        }
        return ' ';
    }

}
