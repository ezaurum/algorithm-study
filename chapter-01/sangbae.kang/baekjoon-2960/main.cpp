#include <iostream>

using namespace std;

void problem2960(int n, int k);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int k;
    cin >> n;
    cin >> k;

    problem2960(n, k);
    return 0;
}

void problem2960(int n, int k) {
    int array[1001];
    std::fill_n(array, 1001, 1);    // 1이면 소수. 0이면 제거하는수.

    int nth = 1;
    for (int i = 2; i <= n; i++) {
        if (array[i]) {
            int multiple = i;
//            cout << i << " 소수.\n";

            for (int j = multiple; j <= n; j += multiple) {
                if (array[j]) {
                    if (nth == k) {
                        cout << j << "\n";
                        return;
                    }
                    array[j] = 0;
//                    cout << j << " extract  " << nth << "\n";
                    nth++;
                }
            }
        }
    }
}
