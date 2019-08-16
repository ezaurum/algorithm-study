#include <iostream>
#include <vector>

using namespace std;

void add_heap(vector<int>& heap, int value);
void shift_down(vector<int>& heap);

int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<int> heap;
    heap.reserve(100);

    int inputData[] = { 1, 5, 10, 9, 8, 6, 2, 3, 4, 7 };

    for (int val: inputData) {
        add_heap(heap, val);
    }

    for (int val: heap) {
        cout << "heap1: " << val << "\n";
    }

    vector<int> heap2 = { 1, 5, 3, 9, 2 };
    shift_down(heap2);

    for (int val: heap2) {
        cout << "heap2: " << val << "\n";
    }
    return 0;
}

void add_heap(vector<int>& heap, int value) {
    heap.emplace_back(value);
    size_t index = heap.size() - 1;

    while (index != 0) {
        bool comp = heap[index] < heap[index / 2];
        if (!comp) {
            break;
        }

        swap(heap[index], heap[index / 2]);
        index /= 2;
    }
}


// array에 데이터를 다 넣고 heap으로 재구성한다.
void shift_down(vector<int>& heap) {
    int index = heap.size();

    index /= 2; // 자식을 가진 노드부터 시작.
    while (index >= 0) {
        int p = index;

        // child 노드가 있는 동안 계속 내려간다.
        while (p * 2 < heap.size()) {
            int c = (p == 0) ? 1 : p * 2;   // p == 0일때 p * 2 = 0이므로 0일때, child를 1로 강제 설정.
            if (c + 1 < heap.size() && heap[c] > heap[c + 1]) {
                c++;    // 오른쪽 차일드 노드
            }
            if (heap[p] > heap[c]) {
                swap(heap[p], heap[c]);
            } else {
                break;  // 힙이 다 구성되었으므로 다운 종료.
            }
            p = c;
        }
        index--;
    }
}
