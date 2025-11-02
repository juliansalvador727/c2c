#pragma once
#include "graph.h"
#include <string>
#include <vector>

/**
 * @brief Finds the shortest path between two countries in a graph.
 * 
 * @param graph The graph containing countries and their neighbors.
 * @param start ISO3 code of the starting country.
 * @param end ISO3 code of the destination country.
 * @return std::vector<std::string> The sequence of country codes from start to end.
 *         Returns an empty vector if no path exists.
 * 
 * @note Uses BFS, borders are unweighted so no A* nor Dijkstra's (yet).
 */
std::vector<std::string> shortest_path(const Graph& graph, const std::string& start, const std::string& end);

/**
 * @brief Finds the shortest paths (plural) between two countries in a graph.
 * 
 * @param graph The graph containing countries and their neighbors.
 * @param start ISO3 code of the starting country.
 * @param end ISO3 code of the destination country.
 * @return std::vector<std::vector<std::string>> The sequence of country codes from start to end.
 *         Returns an empty vector if no path exists.
 * 
 * @note Uses BFS, borders are unweighted so no A* nor Dijkstra's (yet).
 */
std::vector<std::vector<std::string>> shortest_paths(const Graph& graph, const std::string& start, const std::string& end);