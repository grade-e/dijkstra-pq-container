#include "dijkstra.hpp"
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
  // 노드 ID가 불연속적인 경우
  vector<int> node_ids = {101, 203, 305, 407, 509};
  unordered_map<int, int> id_to_index;
  for (int i = 0; i < node_ids.size(); ++i)
  {
    id_to_index[node_ids[i]] = i;
  }

  int n = node_ids.size();
  int start = 101;

  vector<vector<Edge>> graph(n);
  graph[id_to_index[101]] = {{203, 10}, {407, 30}, {509, 100}};
  graph[id_to_index[203]] = {{305, 50}};
  graph[id_to_index[305]] = {{509, 10}};
  graph[id_to_index[407]] = {{305, 20}, {509, 60}};
  graph[id_to_index[509]] = {};

  Dijkstra d(n, graph, id_to_index);
  vector<int> shortest_paths = d.shortest_paths(start);

  cout << "Shortest distances from vertex " << start << ":\n";
  for (int i = 0; i < n; ++i)
  {
    int node_id = node_ids[i];
    if (shortest_paths[i] == std::numeric_limits<int>::max())
    {
      cout << "Vertex " << node_id << ": INF\n";
    }
    else
    {
      cout << "Vertex " << node_id << ": " << shortest_paths[i] << "\n";
    }
  }

  return 0;
}
