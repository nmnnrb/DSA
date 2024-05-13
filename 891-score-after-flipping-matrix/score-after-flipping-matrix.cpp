#include <vector>
#include <cmath>

class Solution {
public:
    int matrixScore(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Step 1: Ensure that the leftmost bit of each row is 1
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 0) {
                // Toggle the entire row
                for (int j = 0; j < n; ++j) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        
        // Step 2: Ensure that each column has more 1s than 0s
        for (int j = 1; j < n; ++j) {
            int countOnes = 0;
            for (int i = 0; i < m; ++i) {
                countOnes += grid[i][j];
            }
            // If more zeros than ones, toggle the column
            if (countOnes < m - countOnes) {
                for (int i = 0; i < m; ++i) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        
        // Step 3: Calculate the score
        int score = 0;
        for (int i = 0; i < m; ++i) {
            score += binaryToDecimal(grid[i]);
        }
        
        return score;
    }
    
private:
    int binaryToDecimal(const std::vector<int>& binary) {
        int decimal = 0;
        int n = binary.size();
        for (int i = 0; i < n; ++i) {
            decimal += binary[i] * pow(2, n - 1 - i);
        }
        return decimal;
    }
};
