#include "AdjListGraph.h"

static double trafficMultiplier(TrafficLevel t) {
    if (t == TrafficLevel::OFF_PEAK) return 1.0;
    if (t == TrafficLevel::PEAK) return 1.8;
    return 1.3;
}

AdjListGraph::AdjListGraph(int n) : adj(n) {}

void AdjListGraph::addEdge(int u, int v, double baseCost) {
    adj[u].push_back({v, baseCost});
}

void AdjListGraph::setTrafficLevel(TrafficLevel level) {
    traffic = level;
}

const std::vector<std::pair<int,double>>&
AdjListGraph::neighbors(int u) const {

    cached.clear();
    double factor = trafficMultiplier(traffic);

    for (const auto& e : adj[u]) {
        cached.push_back({e.to, e.baseCost * factor});
    }
    return cached;
}

int AdjListGraph::size() const {
    return adj.size();
}
