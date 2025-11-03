#include "graph.h"
#include "pathfinder.h"
#include <iostream>
#include <algorithm>
#include <cctype>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "invalid arg. should be: " << argv[0] << " START->END\n";
        std::cerr << "e.g: " << argv[0] << " CHN->USA\n";
        return 1;
    }
    std::string mode = argv[1];
    std::string arg = argv[2];

    if (!arg.empty() && arg.back() == '\r') {
        arg.pop_back();
    }

    size_t arrow = arg.find("->");
    if (arrow == std::string::npos) {
        std::cerr << "invalid format. Use START->END (e.g. CHN->USA)\n";
        return 1;
    }

    std::string start = arg.substr(0, arrow);
    std::string end = arg.substr(arrow + 2);

    auto trim = [](std::string& s) {
    // leading
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
        [](unsigned char ch){ return !std::isspace(ch); }));
    // trailing
    s.erase(std::find_if(s.rbegin(), s.rend(),
        [](unsigned char ch){ return !std::isspace(ch); }).base(), s.end());
    };

    trim(start);
    trim(end);

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

        auto strip_spaces = [](std::string &s){
        s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());
        };
        for (auto &path : shortest) {
            for (auto &country : path) {
                strip_spaces(country);
            }
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

}