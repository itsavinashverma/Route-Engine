#ifndef KSTOPROUTER_H
#define KSTOPROUTER_H

#include "IRouter.h"

class KStopRouter : public IRouter {
public:
    RouteResult compute(const Graph& graph, const Query& query) override;
};

#endif
