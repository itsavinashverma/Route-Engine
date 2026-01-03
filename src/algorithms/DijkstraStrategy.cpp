#include "DijkstraStrategy.h"
#include <queue>
#include <limits>
#include <vector>
#include <algorithm>

RouteResult DijkstraStrategy::compute(const Graph& g, const RouteQuery& q) {
    int n = g.size();
    std::vector<double> dist(n, std::numeric_limits<double>::infinity());
    std::vector<int> parent(n, -1);

    dist[q.src] = 0;

    std::priority_queue<
        std::pair<double,int>,
        std::vector<std::pair<double,int>>,
        std::greater<std::pair<double,int>>
    > pq;

    pq.push({0, q.src});

    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();
        double d = top.first;
        int u = top.second;

        if (u == q.dst) break;

        for (const auto& edge : g.neighbors(u)) {
            int v = edge.first;
            double w = edge.second;

            if (d + w < dist[v]) {
                dist[v] = d + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    RouteResult res;
    res.cost = (dist[q.dst] == std::numeric_limits<double>::infinity()) ? -1 : dist[q.dst];

    // reconstruct path
    if (res.cost != -1) {
        for (int v = q.dst; v != -1; v = parent[v])
            res.path.push_back(v);
        std::reverse(res.path.begin(), res.path.end());
    }

    return res;
}
