#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>
#include <utility>

using namespace std;

using Edge = pair<int, int>; // {destination, weight}

struct Node
{
  int vertex;
  int cost;
  bool operator>(const Node &other) const { return cost < other.cost; }
};

class Dijkstra
{
public:
  Dijkstra(int n, const vector<vector<Edge>> &graph, const unordered_map<int, int> &id_to_index)
      : n(n), graph(graph), id_to_index(id_to_index) {}
  vector<int> shortest_paths(int start);
  int shortest_path(int start, int target);

private:
  int n;
  const vector<vector<Edge>> &graph;
  const unordered_map<int, int> &id_to_index;
};