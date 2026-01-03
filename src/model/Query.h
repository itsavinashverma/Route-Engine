#ifndef QUERY_H
#define QUERY_H

struct Query {
    int source;
    int destination;
    int maxStops;   // -1 if no constraint
};

#endif
