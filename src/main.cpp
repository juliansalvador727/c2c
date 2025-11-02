#include "graph.h"
#include "pathfinder.h"
#include <iostream>

int main() {
    Graph graph;
    graph.load_from_csv("data/borders_iso3.csv");

    std::string start, end;
    std::cout << "Enter start country (ISO3): ";
    std::cin >> start;
    std::cout << "Enter end country (ISO3): ";
    std::cin >> end;

    auto paths = shortest_paths(graph, start, end);

    for (auto& p : paths) {
        for (auto& c : p) std::cout << c << " ";
        std::cout << "\n";
    }

    return 0;
}
