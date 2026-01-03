#include "Graph.h"

Graph::Graph(int nodes) : n(nodes), adj(nodes) {}

void Graph::addEdge(int u, int v, int cost) {
    adj[u].push_back({v, cost});
}

int Graph::size() const {
    return n;
}

const std::vector<Edge>& Graph::neighbors(int u) const {
    return adj[u];
}
