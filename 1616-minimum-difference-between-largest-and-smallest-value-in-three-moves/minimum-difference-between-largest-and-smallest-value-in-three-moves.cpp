#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minDifference(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) {
            return 0;
        }

        std::sort(nums.begin(), nums.end());

        // We consider the four possible scenarios:
        int result = INT_MAX;
        result = std::min(result, nums[n-1] - nums[3]); // Change the three smallest elements
        result = std::min(result, nums[n-2] - nums[2]); // Change two smallest elements and the largest element
        result = std::min(result, nums[n-3] - nums[1]); // Change the smallest element and two largest elements
        result = std::min(result, nums[n-4] - nums[0]); // Change the three largest elements

        return result;
    }
};
