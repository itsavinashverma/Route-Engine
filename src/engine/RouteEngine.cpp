#include "RouteEngine.h"

RouteResult RouteEngine::run(const Graph& g,
                             const RouteQuery& q) {
    return strategy->compute(g, q);
}
