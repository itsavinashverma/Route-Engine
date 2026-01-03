#include "ProbabilisticRouter.h"
#include <queue>
#include <cmath>
#include <algorithm>
#include <climits>

RouteResult ProbabilisticRouter::compute(const Graph& graph, const Query& query) {
    int n = graph.size();

    // best[v] = maximum log-probability to reach v
    std::vector<double> best(n, -1e18);
    std::vector<int> parent(n, -1);

    typedef std::pair<double, int> P; // (-logProb, node)
    std::priority_queue<P> pq;

    best[query.source] = 0.0;
    pq.push(P(0.0, query.source));

    while (!pq.empty()) {
        P top = pq.top(); pq.pop();
        double curr = top.first;
        int u = top.second;

        if (curr < best[u]) continue;

        const std::vector<Edge>& nbrs = graph.neighbors(u);
        for (size_t i = 0; i < nbrs.size(); i++) {
            int v = nbrs[i].to;

            // cost is probability * 100
            double p = nbrs[i].cost / 100.0;
            if (p <= 0.0) continue;

            double candidate = curr + std::log(p);
            if (candidate > best[v]) {
                best[v] = candidate;
                parent[v] = u;
                pq.push(P(candidate, v));
            }
        }
    }

    if (best[query.destination] < -1e17) {
        return RouteResult{false, -1, std::vector<int>(), "No reliable path"};
    }

    std::vector<int> path;
    for (int v = query.destination; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    std::reverse(path.begin(), path.end());

    // Convert back to probability percentage
    int probability =
        static_cast<int>(std::exp(best[query.destination]) * 100 + 0.5);

    return RouteResult{
        true,
        probability,
        path,
        ""
    };
}
