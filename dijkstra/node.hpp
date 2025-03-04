#pragma once

struct Node {
    int vertex;
    int cost;
    bool operator>(const Node& other) const {  // for min-heap
        return this->cost > other.cost;
    }
};
