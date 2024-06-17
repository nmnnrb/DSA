#include <cmath>

class Solution {
public:
    bool judgeSquareSum(int c) {
        // Initialize two pointers
        long left = 0;
        long right = static_cast<long>(sqrt(c));
        
        // Iterate using the two pointers approach
        while (left <= right) {
            long sum = left * left + right * right;
            
            if (sum == c) {
                return true;
            } else if (sum < c) {
                left++;
            } else {
                right--;
            }
        }
        
        return false;
    }
};