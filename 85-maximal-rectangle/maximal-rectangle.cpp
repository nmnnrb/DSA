class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) { 
      if (matrix.empty()) return 0;

    int rows = matrix.size();
    int cols = matrix[0].size();

    // Convert characters to integers
    vector<vector<int>> heights(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == '1') {
                heights[i][j] = (i == 0) ? 1 : heights[i - 1][j] + 1;
            }
        }
    }

    int maxArea = 0;
    for (int i = 0; i < rows; ++i) {
        stack<int> s;
        for (int j = 0; j <= cols; ++j) {
            int height = (j == cols) ? 0 : heights[i][j];
            while (!s.empty() && height < heights[i][s.top()]) {
                int h = heights[i][s.top()];
                s.pop();
                int width = s.empty() ? j : j - s.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            s.push(j);
        }
    }

    return maxArea;
        
    }
};