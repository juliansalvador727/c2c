#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>

/**
 * @brief Represents a graph of countries connected by land borders.
 */
class Graph {
    public:
        /**
         * @brief Adjacency list mapping a country to its neighboring countries.
         * e.g. adj["USA"] = {"CAN", "MEX"};
         */
        
        std::unordered_map<std::string, std::unordered_set<std::string>> adj;

        /**
         * @brief Load adjacency list from a CSV file.
         * CSV 
         * 
         * @param filename Path to the CSV file.
         * @note Existing data in the graph will be cleared.
         * @throws std::runtime_error if the file cannot be opened.
         */
        void load_from_csv(const std::string& filename);
};