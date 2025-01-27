#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge
{
    int to;
    int weight;
};

class Dijkstra
{
public:
    Dijkstra(int n, const vector<vector<Edge>> &graph) : n(n), graph(graph) {}
    vector<int> shortest_path(int start);

private:
    struct Node
    {
        int vertex;
        int cost;
        bool operator<(const Node &other) const
        {
            return cost > other.cost;
        }
    };
    int n;
    const vector<vector<Edge>> &graph;
};