#include <iostream>
#include <functional>

using namespace std;

template<typename T>
class Queue {
    static const int max_size = 100;
    T data[max_size];
    int head;
    int tail;

public:
    Queue(): head(0), tail(0) {}

    void in(T a) {
        if ((tail + 1) % max_size == head) {
            throw overflow_error("full");
        }
        data[tail] = a;
        tail = (tail + 1) % max_size;
    }

    T out() {
        if (tail == head) {
            throw underflow_error("empty");
        }
        T a = data[head];
        head = (head + 1) % max_size;
        return a;
    }

    void traverse(function<void(T)> func, bool isReverse = false) {
        if (isReverse) {
            for (int i = (tail - 1) % max_size; i != (head - 1) % max_size; i = (i - 1) % max_size) {
                func(data[i]);
            }
        } else {
            for (int i = head; i != tail; i = (i + 1) % max_size) {
                func(data[i]);
            }
        }
    }
};


int main() {
    Queue<int> queue;
    queue.in(1);
    queue.in(2);
    queue.in(3);
    queue.in(4);
    queue.in(5);

    queue.traverse([](int a) { cout << "queue: " << a << "\n"; }, true);
    queue.traverse([](int a) { cout << "queue: " << a << "\n"; });
    for (int i: { 1, 2, 3, 4, 5 }) {
        cout << queue.out() << "\n";
    }
    return 0;
}