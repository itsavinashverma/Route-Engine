#include "KStopRouter.h"
#include <climits>
#include <algorithm>

RouteResult KStopRouter::compute(const Graph& graph, const Query& query) {
    int n = graph.size();
    std::vector<std::vector<int>> dp(query.maxStops + 2, std::vector<int>(n, INT_MAX));
    std::vector<std::vector<int>> parent(query.maxStops + 2, std::vector<int>(n, -1));

    dp[0][query.source] = 0;

    for (int k = 1; k <= query.maxStops + 1; k++) {
        dp[k] = dp[k - 1];
        for (int u = 0; u < n; u++) {
            if (dp[k - 1][u] == INT_MAX) continue;
            for (auto& e : graph.neighbors(u)) {
                if (dp[k][e.to] > dp[k - 1][u] + e.cost) {
                    dp[k][e.to] = dp[k - 1][u] + e.cost;
                    parent[k][e.to] = u;
                }
            }
        }
    }

    int bestK = -1, bestCost = INT_MAX;
    for (int k = 0; k <= query.maxStops + 1; k++) {
        if (dp[k][query.destination] < bestCost) {
            bestCost = dp[k][query.destination];
            bestK = k;
        }
    }

    if (bestCost == INT_MAX) {
        return {false, -1, {}, "No path within stop limit"};
    }

    std::vector<int> path;
    int v = query.destination, k = bestK;
    while (v != -1) {
        path.push_back(v);
        v = parent[k--][v];
    }
    std::reverse(path.begin(), path.end());

    return {true, bestCost, path, ""};
}
