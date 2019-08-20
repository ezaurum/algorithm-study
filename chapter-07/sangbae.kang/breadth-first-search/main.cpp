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

void breadth_first_search(const Graph9 &graph, int start);


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Graph9 graph; // 양방향 edge 추가.
    graph.vertex[1].push_back(2);
    graph.vertex[2].push_back(1);
    graph.vertex[2].push_back(3);
    graph.vertex[2].push_back(4);
    graph.vertex[2].push_back(5);
    graph.vertex[3].push_back(2);
    graph.vertex[3].push_back(7);
    graph.vertex[4].push_back(2);
    graph.vertex[5].push_back(2);
    graph.vertex[5].push_back(6);
    graph.vertex[6].push_back(5);
    graph.vertex[6].push_back(7);
    graph.vertex[6].push_back(8);
    graph.vertex[7].push_back(3);
    graph.vertex[7].push_back(6);
    graph.vertex[7].push_back(8);
    graph.vertex[8].push_back(6);
    graph.vertex[8].push_back(7);

    breadth_first_search(graph, 1);
    cout << "\n";

    for (int i = 1; i < graph.size; i++) {
        breadth_first_search(graph, i);
        cout << "\n";
    }
    return 0;
}

void breadth_first_search(const Graph9 &graph, int start) {
    int visited[graph.size];
    fill_n(visited, graph.size, 0);

    queue<int> queue;
    queue.push(start);

    while (!queue.empty()) {
        int v = queue.front();
        queue.pop();

        if (visited[v] == 0) {
            visited[v] = 1;
            cout << v << ", ";

            for (int next: graph.vertex[v]) {
                queue.push(next);
            }
        }
    }
}
