class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int start = 0, end = 0, currentCost = 0, maxLength = 0;
        int n = s.size();
        
        while (end < n) {
            // Calculate the cost of changing s[end] to t[end]
            currentCost += abs(s[end] - t[end]);
            
            // If currentCost exceeds maxCost, move the start pointer to the right
            while (currentCost > maxCost) {
                currentCost -= abs(s[start] - t[start]);
                start++;
            }
            
            // Update the maxLength to the current window size if it's valid
            maxLength = max(maxLength, end - start + 1);
            
            // Move the end pointer to the right
            end++;
        }
        
        return maxLength;
    }
};
