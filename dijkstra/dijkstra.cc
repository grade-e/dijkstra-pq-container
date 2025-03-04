#include "dijkstra.hpp"

vector<int> dijkstra(int start, int V, vector<vector<Node>>& graph) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    vector<int> dist(V, numeric_limits<int>::max());

    dist[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int u = current.vertex;
        int currentCost = current.cost;

        // if cost is excceds the table -> skip
        if (currentCost > dist[u]) continue;

        for (const Node& neighbor : graph[u]) {
            int v = neighbor.vertex;
            int c = neighbor.cost;
            int newDist = dist[u] + c;

            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({v, newDist});
            }
        }
    }
    return dist;
}
