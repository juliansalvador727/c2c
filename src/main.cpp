#include "graph.h"
#include "pathfinder.h"
#include <iostream>
#include <algorithm>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "invalid arg. should be: " << argv[0] << " START->END\n";
        std::cerr << "e.g: " << argv[0] << " CHN->USA\n";
        return 1;
    }
    std::string mode = argv[1];
    std::string arg = argv[2];
    size_t arrow = arg.find("->");
    if (arrow == std::string::npos) {
        std::cerr << "invalid format. Use START->END (e.g. CHN->USA)\n";
        return 1;
    }

    std::string start = arg.substr(0, arrow);
    std::string end = arg.substr(arrow + 2);

    std::transform(start.begin(), start.end(), start.begin(), ::toupper);
    std::transform(end.begin(), end.end(), end.begin(), ::toupper);

    Graph graph;
    try {
        graph.load_from_csv("../data/borders_iso3.csv");
    } catch (const std::exception& e) {
        std::cerr << "Error loading borders: " << e.what() << "\n";
        return 1;
    }

    if (mode == "paths") {
        // ./paths called
        auto shortest = shortest_paths(graph, start, end);
        if (shortest.empty()) {
            std::cout << "No path found from " << start << " to " << end << ".\n";
            return 0;
        }
        std::cout << "Found " << shortest.size()
                  << " shortest path(s) from " << start << " to " << end << ":\n";

        for (const auto& path : shortest) {
            for (size_t i = 0; i < path.size(); ++i) {
                std::cout << path[i];
                if (i < path.size() - 1) std::cout << " ";
            }
            std::cout << "\n";
        }
    } else if (mode == "path"){
        // ./path called
        auto path = shortest_path(graph, start, end);
        if (path.empty()) {
            std::cout << "No path found from " << start << " to " << end << ".\n";
            return 0;
        }
        for (size_t i = 0; i < path.size(); ++i) {
            std::cout << path[i];
            if (i < path.size() - 1) std::cout << " ";
        }
        std::cout << "\n";
    }


    // auto path = shortest_path(graph, start, end);

    // if (path.empty()) {
    //     std::cout << "No path found from " << start << " to " << end << ".\n";
    //     return 0;
    // }

    // for (const auto& c : path) {
    //     std::cout << c << " ";
    // }
    // std::cout << "\n";
    // return 0;
}