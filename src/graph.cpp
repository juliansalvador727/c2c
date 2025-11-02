#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

#include "graph.h"

void Graph::load_from_csv(const std::string& filename) {
    adj.clear();

    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }
    
    std::string line{""};
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string country{""}, neighbor{""};

        std::getline(ss, country, ',');
        std::getline(ss, neighbor, ',');

        if (neighbor == "NONE" || neighbor.empty()) {
            adj[country] = {};
        } else {
            adj[country].insert(neighbor);
            adj[neighbor].insert(country);
        }
    }

    file.close();
}