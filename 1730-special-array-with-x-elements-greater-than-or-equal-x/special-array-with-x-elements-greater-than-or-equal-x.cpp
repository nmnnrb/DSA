#include <vector>
#include <algorithm>

class Solution {
public:
    int specialArray(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());  // Step 1: Sort the array

        int n = nums.size();

        // Step 2: Check each possible value of x
        for (int i = 0; i <= n; ++i) {
            int x = i;
            int count = 0;
            
            // Count how many numbers are >= x
            for (int j = 0; j < n; ++j) {
                if (nums[j] >= x) {
                    count = n - j;
                    break;
                }
            }

            // If exactly x numbers are >= x, return x
            if (count == x) {
                return x;
            }
        }

        // If no such x exists, return -1
        return -1;
    }
};
