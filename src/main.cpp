#include <iostream>
#include "graph/AdjListGraph.h"
#include "algorithms/DijkstraStrategy.h"
#include "engine/RouteEngine.h"
#include "algorithms/KStopsStrategy.h"
#include "graph/Traffic.h"
#include <ctime>


void stressTest(int n, int m) {
    AdjListGraph g(n);
    for (int i = 0; i < m; i++) {
        int u = rand() % n;
        int v = rand() % n;
        g.addEdge(u, v, rand() % 100 + 1);
    }

    RouteQuery q{0, n-1, -1};
    DijkstraStrategy d;
    RouteEngine e(&d);

    auto start = clock();
    e.run(g, q);
    auto end = clock();

    std::cout << "Time: "
              << double(end - start) / CLOCKS_PER_SEC
              << " sec\n";
}


int main() {
    AdjListGraph graph(4);
    graph.addEdge(0,1,1);
    graph.addEdge(1,2,2);
    graph.addEdge(0,2,4);
    graph.addEdge(2,3,1);

    
RouteQuery q1{0, 3, -1};
RouteQuery q2{0, 3, 1};



DijkstraStrategy d1;
KStopsStrategy d2;


RouteEngine e1(&d1);
RouteEngine e2(&d2);

// graph.setTrafficLevel(TrafficLevel::OFF_PEAK);
// std::cout << "Off-peak cost: "
//           << e1.run(graph, q1) << "\n";

// graph.setTrafficLevel(TrafficLevel::PEAK);
// std::cout << "Peak-hour cost: "
//           << e1.run(graph, q1) << "\n";

RouteResult r1 = e1.run(graph, q1);

std::cout << "Cost: " << r1.cost << "\n";
std::cout << "Path: ";
for (int v : r1.path)
    std::cout << v << " ";
std::cout << "\n";
RouteResult r2 = e2.run(graph, q2);

std::cout << "Cost: " << r2.cost << "\n";
std::cout << "Path: ";
for (int v : r2.path)
    std::cout << v << " ";
std::cout << "\n";


// std::cout << "Shortest path: " << e1.run(graph, q1) << "\n";
// std::cout << "Cheapest (1 stop): " << e2.run(graph, q2) << "\n";

 stressTest(10000, 50000);

    return 0;

}


