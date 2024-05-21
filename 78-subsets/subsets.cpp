#include <vector>

class Solution {
public:
    void backtrack(int start, std::vector<int>& current, std::vector<int>& nums, std::vector<std::vector<int>>& result) {
        // Add the current subset to the result
        result.push_back(current);
        
        // Explore further elements to add to the current subset
        for (int i = start; i < nums.size(); ++i) {
            // Include nums[i] in the current subset
            current.push_back(nums[i]);
            
            // Move on to the next element
            backtrack(i + 1, current, nums, result);
            
            // Exclude nums[i] from the current subset (backtrack)
            current.pop_back();
        }
    }

    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        
        // Start backtracking from index 0
        backtrack(0, current, nums, result);
        
        return result;
    }
};
