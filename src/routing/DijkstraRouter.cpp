#include "DijkstraRouter.h"
#include <queue>
#include <climits>
#include <algorithm>

RouteResult DijkstraRouter::compute(const Graph& graph, const Query& query) {
    int n = graph.size();
    std::vector<int> dist(n, INT_MAX);
    std::vector<int> parent(n, -1);

    typedef std::pair<int, int> P; // (distance, node)
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;

    dist[query.source] = 0;
    pq.push(P(0, query.source));

    while (!pq.empty()) {
        P top = pq.top();
        pq.pop();

        int d = top.first;
        int u = top.second;

        if (d > dist[u]) continue;

        const std::vector<Edge>& nbrs = graph.neighbors(u);
        for (size_t i = 0; i < nbrs.size(); i++) {
            int v = nbrs[i].to;
            int w = nbrs[i].cost;

            if (dist[v] > d + w) {
                dist[v] = d + w;
                parent[v] = u;
                pq.push(P(dist[v], v));
            }
        }
    }

    if (dist[query.destination] == INT_MAX) {
        return RouteResult{false, -1, std::vector<int>(), "No path exists"};
    }

    std::vector<int> path;
    for (int v = query.destination; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    std::reverse(path.begin(), path.end());

    return RouteResult{true, dist[query.destination], path, ""};
}
