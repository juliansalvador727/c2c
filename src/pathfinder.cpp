#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <functional>

#include "pathfinder.h"

std::vector<std::string> shortest_path(const Graph& graph, const std::string& start, const std::string& end) {
    if (graph.adj.find(start) == graph.adj.end()) {
        std::cerr << "Start country not found: " << start << "\n";
        return {};
    }
    if (graph.adj.find(end) == graph.adj.end()) {
        std::cerr << "End country not found: " << end << "\n";
        return {};
    }

    std::queue<std::string> queue;
    std::unordered_map<std::string, std::string> parent;
    std::unordered_map<std::string, bool> visited;

    queue.push(start);
    visited[start] = true;

    while (!queue.empty()) {
        std::string current = queue.front();
        queue.pop();

        if (current == end) break;

        for (const auto& neighbor : graph.adj.at(current)) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                queue.push(neighbor);
            }
        }
    }

    std::vector<std::string> path;
    if (!visited[end]) return {};

    for (std::string at = end; at != start; at = parent[at]){
        path.push_back(at);
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());

    return path;
}

std::vector<std::vector<std::string>> shortest_paths(const Graph& graph, const std::string& start, const std::string& end) {
    if (graph.adj.find(start) == graph.adj.end()) {
        std::cerr << "Start not found: " << start << "\n";
        return {};
    }
    if (graph.adj.find(end) == graph.adj.end()) {
        std::cerr << "End not found: " << end << "\n";
        return {};
    }

    std::unordered_map<std::string, int> distance; // shortest distance from start
    std::unordered_map<std::string, std::unordered_set<std::string>> parents; // parents at shortest distance
    std::queue<std::string> q;

    distance[start] = 0;
    q.push(start);

    while (!q.empty()) {
        std::string cur = q.front(); q.pop();
        int cur_d = distance[cur];

        //  if node has no adj entry skip
        auto it = graph.adj.find(cur);
        if (it == graph.adj.end()) continue;

        for (const auto& neigh : it->second) {
            if (neigh == cur) continue;
            if (!distance.count(neigh)) {
                // first time seen -> shortest distance found
                distance[neigh] = cur_d + 1;
                parents[neigh].insert(cur);
                q.push(neigh);
            } else if (distance[neigh] == cur_d + 1) {
                // another shortest path found to neigh
                parents[neigh].insert(cur);
            }
        }
    }

    // unreachable
    if (!distance.count(end)) return {};

    // Backtrack: build all paths from end -> start, but prevent cycles by checking current path
    std::vector<std::vector<std::string>> results;
    std::vector<std::string> path;               // building path from end -> start
    std::unordered_set<std::string> in_path;     // quick membership test to avoid cycles (defensive)

    std::function<void(const std::string&)> backtrack = [&](const std::string& node) {
        path.push_back(node);
        in_path.insert(node);

        if (node == start) {
            // reverse to get start -> end
            std::vector<std::string> full(path.rbegin(), path.rend());
            results.push_back(full);
        } else {
            auto itp = parents.find(node);
            if (itp != parents.end()) {
                for (const auto& parent : itp->second) {
                    // do not recurse if parent is already in current path
                    if (in_path.find(parent) != in_path.end()) continue;
                    backtrack(parent);
                }
            }
        }

        in_path.erase(node);
        path.pop_back();
    };

    backtrack(end);
    return results;
}