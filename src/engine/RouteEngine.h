#pragma once
#include "../algorithms/RouteStrategy.h"

class RouteEngine {
    RouteStrategy* strategy;
public:
    RouteEngine(RouteStrategy* s) : strategy(s) {}
    RouteResult run(const Graph& g, const RouteQuery& q);
};
