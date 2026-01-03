#pragma once
#include "../graph/Graph.h"
#include "../engine/RouteQuery.h"
#include "../engine/RouteResult.h"

class RouteStrategy {
public:
    virtual RouteResult compute(const Graph& g,
                                const RouteQuery& q) = 0;
    virtual ~RouteStrategy() {}
};
