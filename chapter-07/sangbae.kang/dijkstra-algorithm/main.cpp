#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define M     99999999
#define NUM_NODE   8

template<typename T, int MAX_SIZE>
struct AdjacentMatrix {
    T vertex[MAX_SIZE + 1][MAX_SIZE + 1];
    const int size = MAX_SIZE;
};

using AdjcentMatrix8 = AdjacentMatrix<int, 9>;

void floyd_washall_algorithm(AdjcentMatrix8& adj, int start);
void bellman_ford_algorithm(const AdjcentMatrix8& adj, int start);
void dijkstra_algorithm(const AdjcentMatrix8& adj, int start);
void dijkstra_algorithm_heap(const AdjcentMatrix8& adj, int start);


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    AdjcentMatrix8 adj = {
            .vertex = {
                    // 0  1  2  3  4  5  6  7  8
                    {  0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 0
                    {  0, 0, 1, 7, 2, M, M, M, M }, // 1
                    {  0, 1, 0, M, M, 2, 4, M, M }, // 2
                    {  0, 7, M, 0, M, M, 2, 3, M }, // 3
                    {  0, 2, M, M, 0, M, M, 5, M }, // 4
                    {  0, M, 2, M, M, 0, 1, M, M }, // 5
                    {  0, M, 4, 2, M, 1, 0, M, 6 }, // 6
                    {  0, M, M, 3, 5, M, M, 0, 2 }, // 7
                    {  0, M, M, M, M, M, 6, 2, 0 }, // 8
            }
    };

    // floyd_washall_algorithm(adj, 1);
    // bellman_ford_algorithm(adj, 1);
    // dijkstra_algorithm_heap(adj, 1);
    dijkstra_algorithm_heap(adj, 1);
    return 0;
}


int get_valid_edge(const AdjcentMatrix8& adj, int i, int j) {
    if (adj.vertex[i][j] != 0 && adj.vertex[i][j] != M) {
        return adj.vertex[i][j];
    }
    return 0;
}


void floyd_washall_algorithm(AdjcentMatrix8& adj, int start) {
    // i -> j 의 shortest path를 구한다. k는 중간에 거쳐가는 vertex
    for (int k = 1; k <= NUM_NODE; k++) {
        for (int i = 1; i <= NUM_NODE; i++) {
            for (int j = 1; j <= NUM_NODE; j++) {
                if (get_valid_edge(adj, i, k) && get_valid_edge(adj, k, j)) {
                    adj.vertex[i][j] = min(adj.vertex[i][j], adj.vertex[i][k] + adj.vertex[k][j]);
                }
            }
        }
    }

    for (int i = 1; i <= NUM_NODE; i++) {
        cout << "shortest: " << start << " -> " << i << " = " << adj.vertex[start][i] << "\n";
    }
}


void bellman_ford_algorithm(const AdjcentMatrix8& adj, int start) {
    int dist[NUM_NODE + 1];
    fill_n(dist, NUM_NODE + 1, M);
    dist[start] = 0;
    int prev_v[NUM_NODE + 1];
    fill_n(prev_v, NUM_NODE + 1, 0);

    bool found = true;
    while (found) {
        found = false;

        for (int i = 1; i <= NUM_NODE; i++) {
            for (int j = 1; j <= NUM_NODE; j++) {
                // j 까지 최단거리 구하기.
                if (dist[j] > dist[i] + adj.vertex[i][j]) {
                    dist[j] = min(dist[j], dist[i] + adj.vertex[i][j]);
                    prev_v[j] = i;
                    found = true;
                }
            }
        }
    }

    for (int i = 1; i <= NUM_NODE; i++) {
        cout << "shortest: " << start << " -> " << i << " = " << dist[i] << "\n";
    }
}


void dijkstra_algorithm(const AdjcentMatrix8& adj, int start) {
    int dist[NUM_NODE + 1];
    fill_n(dist, NUM_NODE + 1, M);
    dist[start] = 0;    // 자신값은 계산에서 제외한다.
    int visited[NUM_NODE + 1];
    fill_n(visited, NUM_NODE + 1, 0);    // 최소위치의 vertex

    for (int j = 1; j <= NUM_NODE; j++) {
        int next_v = -1;
        int min = M;
        // 방문한 적이 없고, 거리가 제일 짧은 vertex를 선택하기.
        for (int i = 1; i <= NUM_NODE; i++) {
            if (visited[i] == 0 && min > dist[i]) {
                min = dist[i];
                next_v = i;
            }
        }
        if (next_v == -1) { // 방문할 vertex가 없으면 오류.
            cout << "error.\n";
            return;
        }
        visited[next_v] = 1;

        for (int i = 1; i <= NUM_NODE; i++) {
            if (visited[i] == 0 && dist[i] > dist[next_v] + adj.vertex[next_v][i]) {
                dist[i] = dist[next_v] + adj.vertex[next_v][i];
            }
        }
    }

    for (int i = 1; i <= NUM_NODE; i++) {
        cout << "shortest: " << start << " -> " << i << " = " << dist[i] << "\n";
    }
}


void dijkstra_algorithm_heap(const AdjcentMatrix8& adj, int start) {
    int dist[NUM_NODE + 1];
    fill_n(dist, NUM_NODE + 1, M);
    dist[start] = 0;    // 자신값은 계산에서 제외한다.

    // first = vertex, second = weight 를 저장한다.
    auto compare = [](pair<int, int> lhs, pair<int, int> rhs) {
        return lhs.second > rhs.second; // default greater
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);

    pq.push(make_pair(start, 0));

    while (!pq.empty()) {
        pair<int, int> vertex = pq.top();
        pq.pop();

        for (int i = 1; i <= NUM_NODE; i++) {
            if (get_valid_edge(adj, vertex.first, i)) {
                if (dist[i] > dist[vertex.first] + adj.vertex[i][vertex.first]) {
                    dist[i] = dist[vertex.first] + adj.vertex[i][vertex.first];
                    pq.push(make_pair(i, dist[i]));
                }
            }
        }
    }

    for (int i = 1; i <= NUM_NODE; i++) {
        cout << "shortest: " << start << " -> " << i << " = " << dist[i] << "\n";
    }
}
