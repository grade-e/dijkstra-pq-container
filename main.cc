#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int weight;
};

struct Node {
    int vertex;
    int cost;
    bool operator<(const Node& other) const {
        return cost > other.cost;
    }
};

vector<int> dijkstra(int start, int n, const vector<vector<Edge>>& graph) {
    vector<int> dist(n, INF);
    dist[start] = 0;

    priority_queue<Node> pq;
    pq.push({start, 0});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int current_vertex = current.vertex;
        int current_cost = current.cost;

        if (current_cost > dist[current_vertex]) continue;

        for (const Edge& edge : graph[current_vertex]) {
            int next_vertex = edge.to;
            int next_cost = current_cost + edge.weight;

            if (next_cost < dist[next_vertex]) {
                dist[next_vertex] = next_cost;
                pq.push({next_vertex, next_cost});
            }
        }
    }

    return dist;
}

int main() {
    int n = 5;
    int start = 0;

    vector<vector<Edge>> graph(n);
    graph[0] = {{1, 10}, {3, 30}, {4, 100}};
    graph[1] = {{2, 50}};
    graph[2] = {{4, 10}};
    graph[3] = {{2, 20}, {4, 60}};
    graph[4] = {};

    vector<int> shortest_paths = dijkstra(start, n, graph);

    cout << "Shortest distances from vertex " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (shortest_paths[i] == INF) {
            cout << "Vertex " << i << ": INF\n";
        } else {
            cout << "Vertex " << i << ": " << shortest_paths[i] << "\n";
        }
    }

    return 0;
}
