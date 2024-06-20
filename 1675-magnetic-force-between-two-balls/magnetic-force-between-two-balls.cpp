class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        // Sort the basket positions
        sort(position.begin(), position.end());
        
        int left = 1; // Minimum possible distance
        int right = position.back() - position.front(); // Maximum possible distance
        
        while (left < right) {
            int mid = left + (right - left + 1) / 2; // Midpoint distance candidate
            
            if (canPlaceBalls(position, m, mid)) {
                left = mid; // Try for a larger distance
            } else {
                right = mid - 1; // Try for a smaller distance
            }
        }
        
        return left;
    }
    
    bool canPlaceBalls(const vector<int>& position, int m, int minDist) {
        int count = 1; // Place the first ball in the first basket
        int lastPos = position[0]; // Position of the last placed ball
        
        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - lastPos >= minDist) {
                count++; // Place the next ball
                lastPos = position[i];
                
                if (count == m) {
                    return true; // All balls are placed successfully
                }
            }
        }
        
        return false; // Not all balls could be placed with at least minDist distance
    }
};
