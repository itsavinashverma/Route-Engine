# Route Optimization Engine (C++)

## Overview

A **DSA-heavy C++ project** implementing multiple graph algorithms within a unified routing engine.
The project focuses on **algorithm selection, constraints, and performance analysis**, rather than UI or product features.

It demonstrates how the **same graph abstraction** can support different optimization goals using classic data structures and algorithms.

---

## Key Features

* Modular graph abstraction (adjacency list)
* Strategy-based routing algorithms
* Constraint-aware pathfinding
* Traffic-dependent dynamic edge weights
* Empirical performance benchmarking

---

## Algorithms Implemented

### 1. Dijkstra’s Algorithm (Shortest Path)

* Uses min-heap (priority queue)
* Optimizes total path cost

**Time Complexity:** `O(E log V)`
**Space Complexity:** `O(V)`

---

### 2. Cheapest Path with K Stops (BFS-based)

* Limits the number of intermediate stops
* Useful for constrained routing scenarios

**Time Complexity:** `O(K × E)`
**Space Complexity:** `O(V)`

---

### 3. Traffic-Aware Dijkstra

* Edge weights adjusted dynamically using traffic multipliers
* Same algorithm, different cost model

Traffic multipliers:

* Off-peak: `1.0`
* Normal: `1.3`
* Peak: `1.8`

**Time Complexity:** `O(E log V)`
**Key Insight:** Algorithm remains unchanged; only graph weights vary.

---

### 4. Stress Testing & Benchmarking

* Random graph generation
* Measures real execution time using `clock()`
* Demonstrates scalability beyond theoretical Big-O

---

## Project Structure

```
route-engine/
 ├── src/
 │   ├── graph/
 │   │   ├── Graph.h
 │   │   ├── AdjListGraph.h / .cpp
 │   │   └── Traffic.h
 │   ├── algorithms/
 │   │   ├── RouteStrategy.h
 │   │   ├── DijkstraStrategy.h / .cpp
 │   │   └── KStopsStrategy.h / .cpp
 │   ├── engine/
 │   │   ├── RouteEngine.h / .cpp
 │   │   └── RouteQuery.h
 │   └── main.cpp
 └── README.md
```

---

## How to Build and Run

From the `src` directory:

```bash
g++ -std=c++17 main.cpp graph/AdjListGraph.cpp algorithms/DijkstraStrategy.cpp algorithms/KStopsStrategy.cpp engine/RouteEngine.cpp -o engine
```

Run:

```bash
./engine
```

---

## Sample Output

```
Off-peak cost: 4
Peak-hour cost: 7.2
Shortest path: 7.2
Cheapest (1 stop): 7.2

Running stress test...
Time: 0.08 sec
```

---

## Why This Project Is DSA-Focused

* Multiple graph algorithms with different paradigms (Dijkstra, BFS)
* Emphasis on **constraints** (stops, traffic)
* Explicit time and space complexity analysis
* Stress testing on large graphs
* Clean separation between algorithms and data structures

---

## in Short

**Route Optimization Engine (C++)**

* Implemented multiple graph algorithms (Dijkstra, BFS with K-stops) using a strategy-based architecture
* Designed traffic-aware dynamic edge weighting without modifying core algorithms
* Performed time and space complexity analysis and stress-tested on large random graphs
* Focused on algorithmic trade-offs, scalability, and clean abstractions



## Algorithms Implemented

### 1. Dijkstra (Shortest Path)
Time: O(E log V)  
Space: O(V)

### 2. K-Stops BFS (Cheapest Path)
Time: O(K * E)  
Space: O(V)

### 3. Traffic-Aware Dijkstra
Time: O(E log V)  
Note: Dynamic edge weights

### 4. Binary Search + BFS (Min Effort Path)
Time: O(log W * (V + E))  
Space: O(V)
