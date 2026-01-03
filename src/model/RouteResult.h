#ifndef ROUTERESULT_H
#define ROUTERESULT_H

#include <vector>
#include <iostream>

struct RouteResult {
    bool success;
    int totalCost;
    std::vector<int> path;
    std::string reason;
};

inline std::ostream& operator<<(std::ostream& os, const RouteResult& r) {
    if (!r.success) {
        os << "Route failed: " << r.reason;
        return os;
    }

    os << "Cost = " << r.totalCost << "\nPath: ";
    for (int v : r.path) os << v << " ";
    return os;
}

#endif
