#pragma once
#include <vector>

struct RouteResult {
    double cost;
    std::vector<int> path;  // src → dst
};
