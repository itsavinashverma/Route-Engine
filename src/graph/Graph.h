#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

struct Edge {
    int to;
    int cost;
};

class Graph {
private:
    int n;
    std::vector<std::vector<Edge>> adj;

public:
    Graph(int nodes);
    void addEdge(int u, int v, int cost);
    int size() const;
    const std::vector<Edge>& neighbors(int u) const;
};

#endif
