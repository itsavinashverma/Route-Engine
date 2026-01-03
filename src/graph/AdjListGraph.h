#pragma once
#include "Graph.h"
#include "Traffic.h"

class AdjListGraph : public Graph {
    struct Edge {
        int to;
        double baseCost;
    };

    std::vector<std::vector<Edge>> adj;
TrafficLevel traffic = TrafficLevel::NORMAL;
mutable std::vector<std::pair<int,double>> cached;


public:
    AdjListGraph(int n);

    void addEdge(int u, int v, double baseCost);
    void setTrafficLevel(TrafficLevel level);

   const std::vector<std::pair<int,double>>& neighbors(int u) const override;
    int size() const override;
};


// #pragma once
// #include "Graph.h"

// class AdjListGraph : public Graph {
//     std::vector<std::vector<std::pair<int,double>>> adj;

// public:
//     AdjListGraph(int n);
//     void addEdge(int u, int v, double w) override;
//     const std::vector<std::pair<int,double>>& neighbors(int u) const override;
//     int size() const override;
// };
