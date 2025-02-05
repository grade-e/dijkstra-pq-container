#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <utility>

using namespace std;

using Edge = pair<int, int>; // {destination, weight}

struct Node
{
  int vertex;
  int cost;
  bool operator>(const Node &np) const { return this->cost > np.cost; }
};

class Dijkstra
{
public:
  Dijkstra(int n, const vector<vector<Edge>> &graph) : n(n), graph(graph) {}
  vector<int> shortest_paths(int start);
  int shortest_path(int start, int target);

private:
  int n;
  const vector<vector<Edge>> &graph;
};