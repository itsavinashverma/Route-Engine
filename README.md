#  Route Engine — Modular Pathfinding System (C++)

## Overview

**Route Engine** is a modular, command-line routing system implemented in **C++**, designed to compute optimal paths in a directed graph under **different real-world optimization objectives**.

Instead of hardcoding a single shortest-path algorithm, the engine supports **pluggable routing strategies** that model practical constraints such as terrain difficulty, hop limits, and unreliable connections.

---

## Key Features

* **Modular architecture** with clear separation of concerns
* **Multiple routing strategies**, selectable at runtime
* **CLI-based interface** (tool-like, not a demo)
* Compatible with **Windows (MinGW)** and Linux toolchains

---

## Routing Strategies Implemented

| Strategy                  | Objective                    | Real-World Analogy              |
| ------------------------- | ---------------------------- | ------------------------------- |
| **Dijkstra**              | Minimize total cost          | Fastest / cheapest route        |
| **K-Stop Routing**        | Minimize cost with hop limit | Limited transfers or stops      |
| **Minimax (Terrain)**     | Minimize worst edge cost     | Safest terrain / weakest link   |
| **Probabilistic Routing** | Maximize success probability | Reliable networks under failure |

---

## Architecture

```
src/
├── graph/          # Graph data structures
├── model/          # Query & result models
├── routing/        # Routing strategies (Strategy Pattern)
└── main.cpp        # CLI entry point
```

### Design Principles

* **Graph** → data only
* **Router** → algorithm only
* **Query** → constraints
* **RouteResult** → structured output

This design allows **new routing policies** to be added without modifying existing logic.

---

## Build Instructions (Windows – PowerShell)

### Requirements

* MinGW (GCC ≥ 6.3)
* C++17 support

### Compile

```powershell
g++ -std=c++17 src/main.cpp `
src/graph/Graph.cpp `
src/routing/DijkstraRouter.cpp `
src/routing/KStopRouter.cpp `
src/routing/MinimaxRouter.cpp `
src/routing/ProbabilisticRouter.cpp `
-o route_engine.exe
```

### Run

```powershell
.\route_engine.exe --algo=dijkstra --src=0 --dst=4
```

---

## CLI Usage

```text
route_engine.exe --algo=<algorithm> --src=<source> --dst=<destination> [--k=<stops>]
```

### Algorithms

* `dijkstra`
* `kstop` (requires `--k`)
* `minimax`
* `prob`

### Examples

```powershell
.\route_engine.exe --algo=dijkstra --src=0 --dst=4
.\route_engine.exe --algo=kstop --src=0 --dst=4 --k=2
.\route_engine.exe --algo=minimax --src=0 --dst=4
.\route_engine.exe --algo=prob --src=0 --dst=4
```

---

## Probabilistic Routing (Technical Note)

For probabilistic routing, edge weights represent **success probability (%)**.
The engine maximizes end-to-end reliability using **log-space accumulation** to avoid floating-point underflow:

```
maximize Π(p_i)  →  maximize Σ log(p_i)
```

This approach is commonly used in **network routing and reliability modeling**.

---

## Sample Output

```
Cost = 73
Path: 0 3 2 4
```

> Interpretation depends on routing strategy (cost, bottleneck, or probability).

---

## Why This Project

This project focuses on **engineering design**, not just algorithms:

* Runtime-selectable strategies
* Clean abstractions
* Realistic constraints
* CLI-based execution

It is intentionally scoped to demonstrate **system design clarity** rather than feature bloat.

---

## Author

**Avinash Verma**
IIT Delhi
