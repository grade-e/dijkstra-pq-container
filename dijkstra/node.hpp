#pragma once

struct Node {
    int id;                                // vertex number(id)
    int cost;                                  // cost to reach the vertex
    bool operator>(const Node& other) const {  // for min-heap
        return this->cost > other.cost;
    }
};
