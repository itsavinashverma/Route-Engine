#pragma once
#include <vector>
#include <utility>

class Graph {
public:
    virtual void addEdge(int u, int v, double w) = 0;
    virtual const std::vector<std::pair<int,double>>& neighbors(int u) const = 0;
    virtual int size() const = 0;
    virtual ~Graph() {}
};
