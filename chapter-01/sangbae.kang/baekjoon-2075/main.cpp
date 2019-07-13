#include <iostream>
#include <queue>

using namespace std;

void problem2075(int* pArray, int n);
void problem2075v2();


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#if 0
    int n;
    cin >> n;
    int* matrix = new int[n * n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i*n + j];
        }
    }

    problem2075(matrix, n);
#endif

    problem2075v2();
    return 0;
}

int getMin(int* pArray, int* rowIndex, int n) {
    int minVal = INT32_MAX;
    int minRow = 0;

    for (int i = 0; i < n; i++) {
        if (rowIndex[i] == n)   // row의 모든 값을 더 사용했음.
            continue;

        int currentRowVal = pArray[rowIndex[i] * n + i];
        if (minVal > currentRowVal) {
            minRow = i;
            minVal = currentRowVal;
        }
    }
    rowIndex[minRow]++;
    return minVal;
}

//  이 함수를 사용하면 메모리 초과가 발생해서 실패함.
//  여기서 heap을 써서 특정길이만 저장하는 방법을 쓰면
//  메모리초과는 발생하지 않음.
//
//  heap을 쓸 경우, '채워진 수에는 한 가지 특징이 있는데, 모든 수는
//  자신의 한 칸 위에 있는 수보다 크다는 것이다.' 조건을 전혀 활용할 수 없음.
//
void problem2075(int *pArray, int n) {
    int rowIndex[1500];     // row별로 min값을 추출할 index.

    std::fill_n(rowIndex, 1500, 0);

    // 개별 row는 이미 소팅되어 있으므로 merge 소팅하듯이 min값을
    // 계속 추출할 수 있다.
    for (int i = 0; i < n; i++) {
        int val = getMin(pArray, rowIndex, n);
        if (i == n - 1) {
            cout << val << "\n";
        }
    }
}


// 답. 모범 답안이 없어서 이게 문제 의도에 부합하는지 확신할 수 없음.
//
void problem2075v2() {
    priority_queue<int, vector<int>, greater<>> pqueue;     // compare default가 less<T>라
                                                            // 내림차순이 기본이다.

    int n;
    cin >> n;

    for (int i = 0; i < n * n; i++) {
        int val;
        cin >> val;

        pqueue.push(val);
        if (pqueue.size() > n) {    // n개만 pqueue에 유지한다.
            pqueue.pop();
        }
    }
    cout << pqueue.top() << "\n";
}


