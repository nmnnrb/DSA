#include <vector>

class Solution {
public:
    int minPatches(std::vector<int>& nums, int n) {
        long long miss = 1;  // The smallest number that cannot be formed
        int i = 0;
        int patches = 0;
        int size = nums.size();
        
        while (miss <= n) {
            if (i < size && nums[i] <= miss) {
                // If the current number in nums can help us cover `miss`
                miss += nums[i];
                i++;
            } else {
                // If we need to patch the array to cover `miss`
                miss += miss;
                patches++;
            }
        }
        
        return patches;
    }
};