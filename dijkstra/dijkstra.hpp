#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
constexpr int INF = numeric_limits<int>::max();

struct Node {
    int vertex;
    int cost;
    bool operator>(const Node& other) const {  // for min-heap
        return this->cost > other.cost;
    }
};

vector<int> dijkstra(int start, int V, vector<vector<Node>>& graph);