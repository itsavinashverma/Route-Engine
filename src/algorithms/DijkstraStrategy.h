#pragma once
#include "RouteStrategy.h"

class DijkstraStrategy : public RouteStrategy {
public:
    RouteResult compute(const Graph& g,
                        const RouteQuery& q) override;
};
