#pragma once
#include "RouteStrategy.h"

class KStopsStrategy : public RouteStrategy {
public:
    RouteResult compute(const Graph& g,
                        const RouteQuery& q) override;
};
