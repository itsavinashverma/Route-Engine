#ifndef PROBABILISTICROUTER_H
#define PROBABILISTICROUTER_H

#include "IRouter.h"

class ProbabilisticRouter : public IRouter {
public:
    RouteResult compute(const Graph& graph, const Query& query) override;
};

#endif
