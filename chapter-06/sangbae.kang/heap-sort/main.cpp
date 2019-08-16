#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void shift_down(vector<int>& heap, int p, int n);


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> data = { 8, 2, 6, 4, 5 };

    for (int i = int(data.size()) / 2; i >= 0; i--) {
        shift_down(data, i, data.size());
    }

    for (int i = int(data.size()) - 1; i > 0; i--) {
        swap(data[i], data[0]);
        shift_down(data, 0, i);
    }

    reverse(data.begin(), data.end());
    for (int val: data) {
        cout << "value: " << val << "\n";
    }
    return 0;
}


// array에 데이터를 다 넣고 heap으로 재구성한다.
void shift_down(vector<int>& heap, int p, int n) {
    // child 노드가 있는 동안 계속 내려간다.
    int c = (p == 0) ? 1 : p * 2;   // p == 0일때 p * 2 = 0이므로 0일때, child를 1로 강제 설정.
    while (c < n) {
        if (c + 1 < n && heap[c] > heap[c + 1]) {
            c++;    // 오른쪽 차일드 노드
        }
        if (heap[p] > heap[c]) {
            swap(heap[p], heap[c]);
        } else {
            break;  // 힙이 다 구성되었으므로 다운 종료.
        }
        c *= 2;
    }
}
