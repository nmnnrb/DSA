#include <vector>
#include <algorithm>

class Solution {
public:
    int minMovesToSeat(std::vector<int>& seats, std::vector<int>& students) {
        // Step 1: Sort both the seats and students arrays
        std::sort(seats.begin(), seats.end());
        std::sort(students.begin(), students.end());
        
        // Step 2: Calculate the sum of absolute differences
        int minMoves = 0;
        for (size_t i = 0; i < seats.size(); ++i) {
            minMoves += std::abs(seats[i] - students[i]);
        }
        
        // Step 3: Return the total minimum moves
        return minMoves;
    }
};
