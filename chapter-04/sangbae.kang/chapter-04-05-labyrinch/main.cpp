#include <iostream>
#include <vector>

using namespace std;

int maze[7][7] = {
        { 2, 2, 2, 2, 2, 2, 2 },
        { 2, 0, 0, 0, 0, 0, 2 },
        { 2, 0, 2, 0, 2, 0, 2 },
        { 2, 0, 0, 2, 0, 2, 2 },
        { 2, 2, 0, 2, 0, 2, 2 },
        { 2, 0, 0, 0, 0, 0, 2 },
        { 2, 2, 2, 2, 2, 2, 2 },
};
int success = 0;
// 1,1 -> 5,5
int endI = 5;
int endJ = 5;

int traverse(int i, int j);

vector<pair<int, int>> stack;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 스택 크기 지정
    stack.reserve(20);

    if (!traverse(1, 1)) {
        printf("path not found\n");
    }
    return 0;
}

int traverse(int i, int j) {
    maze[i][j] = 1;
    stack.emplace_back(make_pair(i, j));

    if (i == endI && j == endJ) {
        int m = 0;
        for (auto& p: stack) {
            printf("%d: (%d, %d)\n", m++, p.first, p.second);
        }
        success = 1;
    }

    if (!success) {
        if (maze[i][j + 1] == 0) traverse(i, j + 1);
        if (maze[i + 1][j] == 0) traverse(i + 1, j);
        if (maze[i][j - 1] == 0) traverse(i, j - 1);
        if (maze[i - 1][j] == 0) traverse(i - 1, j);
    }

    stack.pop_back();
    return success;
}