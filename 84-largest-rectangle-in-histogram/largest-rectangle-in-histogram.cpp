class Solution {
    private:
    vector<int> nextpoint(vector<int>& heights){
        stack<int> s;
        vector<int> ans(heights.size());
        s.push(-1);
        for(int i = heights.size() -1 ; i >= 0 ;i--){
            int curr = heights[i];
            while(s.top()!= -1 && curr <= heights[s.top()]){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

      vector<int> prevpoint(vector<int>& heights){
        stack<int> s;
        vector<int> ans(heights.size());
        s.push(-1);
        for(int i = 0 ; i <= heights.size() -1 ;i++){
            int curr = heights[i];
            while(s.top()!= -1 && curr <= heights[s.top()]){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
    int area = INT_MIN;
    vector<int> next;
    next = nextpoint(heights);
    vector<int> prev;
    prev = prevpoint(heights);

    for(int i = 0;i < heights.size() ; i++){
         if(next[i] == -1) {
                next[i] = heights.size();
            }
        int newArea = (next[i] - prev[i] -1) * (heights[i]);
        area = max(area, newArea);
    }
    return area;
    }
};