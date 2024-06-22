#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;  // Base case: there's one way to have a sum of 0 (empty subarray)
        
        int currentSum = 0;
        int result = 0;
        
        for (int num : nums) {
            // Increment currentSum if the number is odd
            currentSum += (num % 2 == 1) ? 1 : 0;
            
            // Check if there exists a prefix sum such that currentSum - prefixSum = k
            if (prefixCount.find(currentSum - k) != prefixCount.end()) {
                result += prefixCount[currentSum - k];
            }
            
            // Record the current prefix sum
            prefixCount[currentSum]++;
        }
        
        return result;
    }
};