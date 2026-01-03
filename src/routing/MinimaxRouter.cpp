#include "MinimaxRouter.h"
#include <queue>
#include <climits>
#include <algorithm>

RouteResult MinimaxRouter::compute(const Graph& graph, const Query& query) {
    int n = graph.size();

    // bottleneck[v] = minimum possible maximum edge cost to reach v
    std::vector<int> bottleneck(n, INT_MAX);
    std::vector<int> parent(n, -1);

    typedef std::pair<int, int> P; // (bottleneckCost, node)
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;

    bottleneck[query.source] = 0;
    pq.push(P(0, query.source));

    while (!pq.empty()) {
        P top = pq.top(); pq.pop();
        int currMax = top.first;
        int u = top.second;

        if (currMax > bottleneck[u]) continue;

        const std::vector<Edge>& nbrs = graph.neighbors(u);
        for (size_t i = 0; i < nbrs.size(); i++) {
            int v = nbrs[i].to;
            int w = nbrs[i].cost;

            int candidate = std::max(currMax, w);
            if (candidate < bottleneck[v]) {
                bottleneck[v] = candidate;
                parent[v] = u;
                pq.push(P(candidate, v));
            }
        }
    }

    if (bottleneck[query.destination] == INT_MAX) {
        return RouteResult{false, -1, std::vector<int>(), "No feasible terrain path"};
    }

    std::vector<int> path;
    for (int v = query.destination; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    std::reverse(path.begin(), path.end());

    return RouteResult{
        true,
        bottleneck[query.destination],
        path,
        ""
    };
}
