#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

void problem2822(int n, int nth);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    problem2822(8, 5);

    return 0;
}

void problem2822(int n, int nth) {
    int vals[8 + 1];

    for (int i = 0; i < 8; i++) {
        cin >> vals[i];
    }

    priority_queue<int, vector<int>, greater<>> pqueue;
    for (int i = 0; i < 8; i++) {
        if (pqueue.size() < nth) {
            pqueue.push(vals[i]);
//            cout << vals[i] << " insert " << i << "\n";
        } else {
            if (pqueue.top() < vals[i]) {
                // 값을 -1 으로 설정해서 합계에서 제외하도록 한다.
                for (int j = 0; j < i; j++) {
                    if (pqueue.top() == vals[j]) {
                        pqueue.pop();
//                        cout << vals[j] << " remove " << j << "\n";
                        vals[j] = -1;
                        pqueue.push(vals[i]);
//                        cout << vals[i] << " insert " << i << "\n";
                        break;
                    }
                }
            } else {
//                cout << vals[i] << " remove " << i << "\n";
                vals[i] = -1;
            }
        }
    }
    int sum = 0;
    while (!pqueue.empty()) {
        sum += pqueue.top();
        pqueue.pop();
    }
    cout << sum << "\n";

    for (int num = 0, i = 0; i < 8; i++) {
        if (vals[i] > -1) {
            cout << i + 1 << ((num == 4) ? "\n" : " ");
            num++;
        }
    }
}

