#include "dijkstra.hpp"

vector<int> Dijkstra::shortest_paths(int start)
{
  vector<int> dist(n, std::numeric_limits<int>::max());
  dist[start] = 0;

  priority_queue<Node, vector<Node>, greater<Node>> pq;
  pq.push({start, 0});

  while (!pq.empty())
  {
    Node current = pq.top();
    pq.pop();

    int u = current.vertex;
    int d = current.cost;

    if (d > dist[u])
      continue;

    for (const Edge &edge : graph[u])
    {
      int v = edge.first;
      int weight = edge.second;
      int new_dist = d + weight;

      if (new_dist < dist[v])
      {
        dist[v] = new_dist;
        pq.push({v, new_dist});
      }
    }
  }

  return dist;
}

int Dijkstra::shortest_path(int start, int target)
{
  vector<int> dist(n, std::numeric_limits<int>::max());
  dist[start] = 0;

  priority_queue<Node, vector<Node>, greater<Node>> pq;
  pq.push({start, 0});

  while (!pq.empty())
  {
    Node current = pq.top();
    pq.pop();

    int u = current.vertex;
    int d = current.cost;

    if (u == target)
    {
      return d;
    }

    if (d > dist[u])
      continue;

    for (const Edge &edge : graph[u])
    {
      int v = edge.first;
      int weight = edge.second;
      int new_dist = d + weight;

      if (new_dist < dist[v])
      {
        dist[v] = new_dist;
        pq.push({v, new_dist});
      }
    }
  }

  return -1;
}