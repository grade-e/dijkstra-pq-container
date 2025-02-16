#include <iostream>
#include <limits>
#include <queue>
#include <vector>

#include "dijkstra.hpp"

using namespace std;

int main() {
    int n = 5;      // number of vertices
    int start = 0;  // starting vertex

    vector<vector<Node>> graph(n);  // adjacency list
    graph[0].push_back({1, 10});    // 0 → 1, 10
    graph[0].push_back({3, 30});    // 0 → 3, 30
    graph[0].push_back({4, 100});   // 0 → 4, 100
    graph[1].push_back({2, 50});    // 1 → 2, 50
    graph[2].push_back({4, 10});    // 2 → 4, 10
    graph[3].push_back({2, 20});    // 3 → 2, 20
    graph[3].push_back({4, 60});    // 3 → 4, 60
    vector<int> shortest_paths = dijkstra(start, n, graph);

    cout << "Shortest distances from vertex " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (shortest_paths[i] == std::numeric_limits<int>::max()) {
            cout << "Vertex " << i << ": INF\n";
        } else {
            cout << "Vertex " << i << ": " << shortest_paths[i] << "\n";
        }
    }
    return 0;
}
