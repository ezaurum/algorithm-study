#include <iostream>
#include <vector>

#define MAX_NODE 4
#define MAX_EDGE 6

using AdjMatrix = int [MAX_NODE + 1][MAX_NODE + 1];

using namespace std;

vector<int> stack;
int path;
int visit;
int startNode;

void eulerian_trail(AdjMatrix& adj, int node);


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    AdjMatrix adj = {
            { 0, 0, 0, 0, 0 },
            { 0, 0, 1, 0, 1 },
            { 0, 1, 0, 1, 2 },
            { 0, 0, 1, 0, 1 },
            { 0, 1, 2, 1, 0 }
    };

    path = 0;
    visit = 0;
    startNode = 1;
    eulerian_trail(adj, startNode);
    if (path == 0) {
        cout << "not found path\n";
    }

    return 0;
}

void eulerian_trail(AdjMatrix& adj, int node) {
    stack.push_back(node);
    // cout << "stack.size: " << stack.size() << ", node: " << node << "\n";

    if (visit == MAX_EDGE && node == startNode) {   // 시작위치로 돌아감.
        path++;
        cout << "path[" << path << "]: ";
        for (int node1: stack) {
            cout << node1 << ", ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= MAX_NODE; i++) {
        // node와 연결된 edge에 대해서.
        if (adj[node][i] != 0) {
            adj[node][i]--;
            adj[i][node]--; // 방향성이면 이 line을 없앰.
            visit++;

            eulerian_trail(adj, i);

            // 원위치하고 다른 path를 찾는다.
            adj[node][i]++;
            adj[i][node]++; // 방향성이면 이 line을 없앰.
            visit--;

            stack.pop_back();
        }
    }
}