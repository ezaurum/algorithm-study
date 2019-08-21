#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template<typename T, int MAX_SIZE>
struct Graph {
    vector<T> vertex[MAX_SIZE];
    const int size = MAX_SIZE;
};

using Graph9 = Graph<int, 9>;

void topological_sort(const Graph9& graph);


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Graph9 graph;
    graph.vertex[1].push_back(3);
    graph.vertex[2].push_back(1);
    graph.vertex[2].push_back(5);
    graph.vertex[3].push_back(4);
    graph.vertex[3].push_back(7);
    graph.vertex[5].push_back(4);
    graph.vertex[5].push_back(6);
    graph.vertex[6].push_back(7);
    graph.vertex[6].push_back(8);
    graph.vertex[8].push_back(7);

    topological_sort(graph);
    return 0;
}


void topological_sort(const Graph9& graph) {
    int in_degrees[graph.size]; // 진입차수 배열
    fill_n(in_degrees, graph.size, 0);

    // 진입 차수 배열을 구성한다.
    for (const vector<int>& vec: graph.vertex) {
        for (const int v: vec) {
            in_degrees[v]++;
        }
    }

    queue<int> q;
    for (int i = 1; i < graph.size; i++) {
        if (in_degrees[i] == 0) {
            q.push(i);
        }
    }

    // q에서 size만큼 꺼내면 모든 vertex를 지난다는 것을 의미한다.
    for (int i = 1; i < graph.size; i++) {
        if (q.empty()) {
            cout << "cycle has begun.\n";
            return;
        }
        int v = q.front();
        q.pop();

        cout << v << ", ";  // 진행.

        // 인접 v에 대해서, 진입차수가 0이면 q.push()함.
        for (int nv: graph.vertex[v]) {
            if (--in_degrees[nv] == 0) {
                q.push(nv);
            }
        }
    }
}