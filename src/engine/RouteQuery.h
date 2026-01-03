#pragma once

struct RouteQuery {
    int src;
    int dst;
    int maxStops;   // -1 if not applicable
};
