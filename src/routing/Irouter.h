#ifndef IROUTER_H
#define IROUTER_H

#include "../graph/Graph.h"
#include "../model/Query.h"
#include "../model/RouteResult.h"

class IRouter {
public:
    virtual RouteResult compute(const Graph& graph, const Query& query) = 0;
    virtual ~IRouter() = default;
};

#endif
