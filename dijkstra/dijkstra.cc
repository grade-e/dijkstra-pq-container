#include "dijkstra.hpp"

vector<int> Dijkstra::shortest_path(int start) {
  vector<int> dist(n, std::numeric_limits<int>::max());
  dist[start] = 0;

  priority_queue<Node> pq;
  pq.push({start, 0});

  while (!pq.empty()) {
    Node current = pq.top();
    pq.pop();

    int current_vertex = current.vertex;
    int current_cost = current.cost;

    if (current_cost > dist[current_vertex])
      continue;

    for (const Edge &edge : graph[current_vertex]) {
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