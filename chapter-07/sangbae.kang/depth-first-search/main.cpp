#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE    8 + 1

int adjMatrix[MAX_SIZE][MAX_SIZE] = {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 1, 0, 1, 0, 0, 0, 0 },
        { 0, 1, 0, 1, 1, 0, 0, 0, 0 },
        { 0, 0, 1, 0, 0, 0, 0, 1, 0 },
        { 0, 1, 1, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 1, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0, 1, 0, 1, 1 },
        { 0, 0, 0, 1, 0, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 0, 0, 1, 1, 0 },
};
int v[MAX_SIZE] = { 0, };

// 연결이 완전하지 않은 그래프
int adjMatrix2[MAX_SIZE][MAX_SIZE] = {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 1, 1, 0, 0, 0, 0, 0 },
        { 0, 1, 0, 1, 1, 0, 0, 0, 0 },
        { 0, 1, 1, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 1, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 1, 1, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 1, 1 },
        { 0, 0, 0, 0, 0, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 0, 0, 1, 1, 0 },
};

void visit(int adj[][MAX_SIZE], int start);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 1; i < MAX_SIZE; i++) {
        fill_n(v, MAX_SIZE, 0);

        visit(adjMatrix, i);
        cout << "\n";
    }

    fill_n(v, MAX_SIZE, 0);
    for (int i = 1; i < MAX_SIZE; i++) {
        if (v[i] == 0) {
            cout << "start: ";
            visit(adjMatrix2, i);
            cout << "\n";
        }
    }

    return 0;
}


void visit(int adj[][MAX_SIZE], int start) {
    v[start] = 1;
    for (int i = 1; i < MAX_SIZE; i++) {
        if (adj[start][i] != 0 && v[i] == 0) {
            cout << start << " -> " << i << ", ";
            visit(adj, i);
        }
    }
}

