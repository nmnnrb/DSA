#include <vector>
#include <algorithm>

class Solution {
public:
    long long maximumImportance(int n, std::vector<std::vector<int>>& roads) {
        std::vector<int> degree(n, 0);
        
        // Count the degree of each city
        for (const auto& road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }
        
        // Create a list of city indices
        std::vector<int> cities(n);
        for (int i = 0; i < n; ++i) {
            cities[i] = i;
        }
        
        // Sort cities by their degrees in descending order
        std::sort(cities.begin(), cities.end(), [&](int a, int b) {
            return degree[a] > degree[b];
        });
        
        // Assign values to cities based on their sorted order
        std::vector<int> importance(n);
        for (int i = 0; i < n; ++i) {
            importance[cities[i]] = n - i;
        }
        
        // Calculate the total importance
        long long totalImportance = 0;
        for (const auto& road : roads) {
            totalImportance += importance[road[0]] + importance[road[1]];
        }
        
        return totalImportance;
    }
};