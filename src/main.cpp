#include <iostream>
#include <string>
#include <unordered_map>

#include "graph/Graph.h"
#include "model/Query.h"

#include "routing/DijkstraRouter.h"
#include "routing/KStopRouter.h"
#include "routing/MinimaxRouter.h"
#include "routing/ProbabilisticRouter.h"

void printUsage() {
    std::cout << "Usage:\n";
    std::cout << "  route_engine.exe --algo=<dijkstra|kstop|minimax|prob> "
                 "--src=<int> --dst=<int> [--k=<int>]\n\n";
    std::cout << "Examples:\n";
    std::cout << "  route_engine.exe --algo=dijkstra --src=0 --dst=4\n";
    std::cout << "  route_engine.exe --algo=kstop --src=0 --dst=4 --k=2\n";
    std::cout << "  route_engine.exe --algo=minimax --src=0 --dst=4\n";
    std::cout << "  route_engine.exe --algo=prob --src=0 --dst=4\n";
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printUsage();
        return 1;
    }

    std::unordered_map<std::string, std::string> args;
    for (int i = 1; i < argc; i++) {
        std::string s(argv[i]);
        size_t pos = s.find('=');
        if (pos != std::string::npos) {
            args[s.substr(0, pos)] = s.substr(pos + 1);
        }
    }

    if (!args.count("--algo") || !args.count("--src") || !args.count("--dst")) {
        printUsage();
        return 1;
    }

    std::string algo = args["--algo"];
    int src = std::stoi(args["--src"]);
    int dst = std::stoi(args["--dst"]);
    int k = args.count("--k") ? std::stoi(args["--k"]) : -1;

    // ---------------- Graph Definition ----------------
    Graph graph(5);

    // Interpretation:
    // Dijkstra/KStop -> cost
    // Minimax       -> terrain difficulty
    // Probabilistic -> success probability (%)

    graph.addEdge(0, 1, 90);
    graph.addEdge(1, 2, 80);
    graph.addEdge(0, 3, 95);
    graph.addEdge(3, 2, 85);
    graph.addEdge(2, 4, 90);

    Query query{src, dst, k};

    RouteResult result;

    if (algo == "dijkstra") {
        DijkstraRouter router;
        result = router.compute(graph, query);
    }
    else if (algo == "kstop") {
        if (k < 0) {
            std::cout << "Error: --k is required for kstop routing\n";
            return 1;
        }
        KStopRouter router;
        result = router.compute(graph, query);
    }
    else if (algo == "minimax") {
        MinimaxRouter router;
        result = router.compute(graph, query);
    }
    else if (algo == "prob") {
        ProbabilisticRouter router;
        result = router.compute(graph, query);
    }
    else {
        std::cout << "Unknown algorithm: " << algo << "\n";
        printUsage();
        return 1;
    }

    std::cout << result << "\n";
    return 0;
}
