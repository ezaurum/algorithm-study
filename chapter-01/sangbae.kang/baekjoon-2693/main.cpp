#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

void problem2693(int n, int nth);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        problem2693(10, 3);
    }

    return 0;
}

void problem2693(int n, int nth) {
    priority_queue<int, vector<int>, greater<>> pqueue;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;

        pqueue.push(val);
//        cout << "<< " << val << "\n";
        if (pqueue.size() > nth) {
//            cout << " " << pqueue.top() << "\n";
            pqueue.pop();
        }
    }

    cout << pqueue.top() << "\n";
}

