#include <iostream>

using namespace std;

void problem15897();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    problem15897();

    return 0;
}

//
// 시간초과로 실패.
//
void problem15897() {
    int n;
    cin >> n;

    int64_t count = 0;
    for (int i = 1; i <= n / 2; i++) {
        count += (n % i == 0) ? n / i : n / i + 1;
    }
    count += 2 * (n / 2) + 1;
    cout << count << "\n";
}

//
//  f(n) = sigma ceiling(n / i)
//
//  제일 끝은 값이 1
//  뒤로부터 끝 ~ n / 2 구간은 값이 2
//  n / 2 ~ n / 3 구간은 값이 3
//  n / 3 ~ n / 4 구간은 값이 4
//  0 ~ n / (n - 1) 구간은 값이 n / 2 올림.
//
//  생각은 했는데 이를 for문으로 코딩할 능력은 없음.
//
void problem15897v2() {
    int n;
    cin >> n;
    int64_t count = 0;

    for (int i = n + 1; i != 0; i = n / ((n / i) + 1)) {
        count += (n / i + 1) * (i - (n / ((n / i) + 1)));
    }
    cout << count << "\n";
}