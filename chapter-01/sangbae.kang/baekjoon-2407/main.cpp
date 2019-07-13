#include <iostream>

#include <stdio.h>

using namespace std;
//using std::ios_base;
//using std::cin;
//using std::cout;
//using std::string;

// 128비트 정수 사용하기인데. = 100 C 27 이면 overflow 발생.
//
int64_t combination(int, int);

void combination2(int n, int m);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int m;

    cin >> n;
    cin >> m;

    combination2(n, m);
    // cout << combination(n, m) << "\n";
    return 0;
}

//
// overflow 이하에서 사용. 100 c 26까지 사용가능.
//
int64_t combination(int n, int m) {
    if (m == 0) {
        return 1;
    }
    return combination(n, m - 1) / m * (n - m + 1);
}

// 파스칼의 삼각형 공식 활용.
//
// overflow 문제 해결을 위해 16자리 이상의 값을
// 별도 자릿수 배열에 저장해서 출력한다.
//
void combination2(int n, int m) {
    int64_t p1[101][101];
    int64_t p2[101][101];

    for (int i = 0; i <= n; i++) {
        p1[i][0] = 1;
        p1[i][i] = 1;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++)
            p2[i][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            p1[i][j] = p1[i - 1][j - 1] + p1[i - 1][j];
            p2[i][j] = p2[i - 1][j - 1] + p2[i - 1][j];
            if (p1[i][j] >= 10000000000000000) {
                p2[i][j]++;
                p1[i][j] -= 10000000000000000;  // 10의 16승.
            }
        }
    }
    if (p2[n][m] == 0) {
        printf("%lld\n", p1[n][m]);
    } else {
        printf("%lld%0.16lld\n", p2[n][m], p1[n][m]);
    }
}