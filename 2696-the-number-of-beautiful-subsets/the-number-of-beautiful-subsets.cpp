#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        return backtrack(nums, k, 0, countMap) - 1; // Subtracting 1 to exclude the empty subset.
    }
    
private:
    int backtrack(vector<int>& nums, int k, int index, unordered_map<int, int>& countMap) {
        if (index == nums.size()) {
            return 1;
        }
        
        int numSubsets = 0;
        
        // Case 1: Exclude nums[index]
        numSubsets += backtrack(nums, k, index + 1, countMap);
        
        // Case 2: Include nums[index] if it forms a beautiful subset
        int currentNum = nums[index];
        if (countMap[currentNum - k] == 0 && countMap[currentNum + k] == 0) {
            countMap[currentNum]++;
            numSubsets += backtrack(nums, k, index + 1, countMap);
            countMap[currentNum]--;
        }
        
        return numSubsets;
    }
};
