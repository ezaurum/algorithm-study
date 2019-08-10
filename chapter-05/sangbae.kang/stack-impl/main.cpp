#include <iostream>
#include <functional>

using namespace std;

template<typename T>
class Stack {
    static const int max_size = 100;
    T data[max_size];
    int sp;

public:
    Stack(): sp(0) {}
    void push(T v) {
        if (sp == max_size) {
            cout << "stack overflow" << "\n";
            return;
        }
        data[sp++] = v;
    }
    T pop() {
        if (sp == 0) {
            throw overflow_error("stack underflow");
        }
        return data[--sp];
    }

    T top() {
        if (sp == 0) {
            throw out_of_range("stack underflow");
        }
        return data[sp - 1];
    }

    /**
     * stack에 포함된 모든 data를 특정한 함수에 적용한다.
     * @param func 함수
     * @param isReverse 데이터 처리 순서
     */
    void traverse(std::function<void(T)> func, bool isReverse = false) {
        if (isReverse) {
            for (int i = sp -1; i >= 0; i--) {
                func(data[i]);
            }
        } else {
            for (int i = 0; i < sp; i++) {
                func(data[i]);
            }
        }
    }
};


int main() {
    Stack<int> stack;

    stack.push(100);
    stack.push(200);
    stack.push(300);
    stack.traverse([](int v) { cout << "stack: " << v << "\n"; }, true);
    stack.traverse([](int v) { cout << "stack: " << v << "\n"; });

    cout << stack.pop() << "\n";
    cout << stack.pop() << "\n";
    cout << stack.pop() << "\n";
//    cout << stack.top() << "\n";  // exception.
//    cout << stack.pop() << "\n";  // exception happens.
    return 0;
}