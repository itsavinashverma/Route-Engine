#include "KStopsStrategy.h"
#include "../engine/RouteResult.h"
#include <queue>
#include <limits>
#include <vector>

RouteResult KStopsStrategy::compute(const Graph& g,
                                    const RouteQuery& q) {

    int n = g.size();
    std::vector<double> cost(n, std::numeric_limits<double>::infinity());
    cost[q.src] = 0;

    std::queue<std::pair<int,int>> qu; // node, stops
    qu.push({q.src, 0});

    while (!qu.empty()) {
        auto curr = qu.front(); qu.pop();
        int u = curr.first;
        int stops = curr.second;

        if (stops > q.maxStops) continue;

        for (const auto& edge : g.neighbors(u)) {
            int v = edge.first;
            double w = edge.second;

            if (cost[u] + w < cost[v]) {
                cost[v] = cost[u] + w;
                qu.push({v, stops + 1});
            }
        }
    }

 //   return cost[q.dst] == std::numeric_limits<double>::infinity() ? -1 : cost[q.dst];
 RouteResult res;
res.cost = (minCost == INF ? -1 : minCost);
res.path = {}; // optional for now (can add later)
return res;

}
