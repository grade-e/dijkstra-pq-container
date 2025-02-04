#include "dijkstra.hpp"
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n = 5;
  int start = 0;

  vector<vector<Edge>> graph(n);
  graph[0] = {{1, 10}, {3, 30}, {4, 100}};
  graph[1] = {{2, 50}};
  graph[2] = {{4, 10}};
  graph[3] = {{2, 20}, {4, 60}};
  graph[4] = {};
  Dijkstra d(n, graph);
  vector<int> shortest_paths = d.shortest_path(start);

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
