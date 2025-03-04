#include "dijkstra.hpp"

vector<int> dijkstra(int start, int nVertex, vector<vector<Node>>& graph) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    vector<int> costs(nVertex, numeric_limits<int>::max());
    costs[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        int vertex = cur.vertex;
        int cost = cur.cost;

        // Skip if we have already found a better path
        if (cost > costs[vertex]) continue;

        // Traverse all neighbors
        for (const Node& neighbor : graph[vertex]) {
            int v = neighbor.vertex;
            int c = neighbor.cost;
            int nc = costs[vertex] + c;

            // Update the cost if we have found a better path
            if (nc < costs[v]) {
                costs[v] = nc;
                pq.push({v, nc});
            }
        }
    }
    return costs;
}
