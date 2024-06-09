#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> remainderCount;
        remainderCount[0] = 1; // To handle cases where the prefix sum itself is divisible by k
        
        int prefixSum = 0;
        int count = 0;
        
        for (int num : nums) {
            prefixSum += num;
            
            // Get remainder of the current prefix sum
            int remainder = prefixSum % k;
            
            // Adjust for negative remainders
            if (remainder < 0) {
                remainder += k;
            }
            
            // If this remainder has been seen before, it means we have found subarrays ending here
            if (remainderCount.find(remainder) != remainderCount.end()) {
                count += remainderCount[remainder];
            }
            
            // Increment the count of this remainder in the map
            remainderCount[remainder]++;
        }
        
        return count;
    }
};
