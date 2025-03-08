#include "dijkstra.hpp"

vector<int> dijkstra(int start, int nVertex, vector<vector<Node>>& graph) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    vector<int> costs(nVertex, INF);
    costs[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        int id = cur.id;
        int cost = cur.cost;

        // Skip if we have already found a better path
        if (cost > costs[id]) continue;

        // Traverse all neighbors
        for (const Node& neighbor : graph[id]) {
            int nid = neighbor.id;
            int ncost = neighbor.cost;
            int new_cost = costs[id] + ncost;

            // Update the cost if we have found a better path
            if (new_cost < costs[nid]) {
                costs[nid] = new_cost;
                pq.push({nid, new_cost});
            }
        }
    }
    return costs;
}
