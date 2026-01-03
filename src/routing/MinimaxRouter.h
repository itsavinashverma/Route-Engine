#ifndef MINIMAXROUTER_H
#define MINIMAXROUTER_H

#include "IRouter.h"

class MinimaxRouter : public IRouter {
public:
    RouteResult compute(const Graph& graph, const Query& query) override;
};

#endif
