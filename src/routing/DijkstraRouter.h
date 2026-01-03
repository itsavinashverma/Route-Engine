#ifndef DIJKSTRAROUTER_H
#define DIJKSTRAROUTER_H

#include "IRouter.h"

class DijkstraRouter : public IRouter {
public:
    RouteResult compute(const Graph& graph, const Query& query) override;
};

#endif
