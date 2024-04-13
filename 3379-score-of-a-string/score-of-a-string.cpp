class Solution {
public:
    int scoreOfString(string s) {
        vector<int> val;
        for(int i = 0; i< s.size() ; i++){
        if('a' <= s[i] && s[i] <= 'z'){
            val.push_back(int(s[i]));
        }
        }
        
        int ans = 0;
        
        for(int i = 0 ; i< val.size() -1 ; i++){
            ans += abs(val[i] - val[i+1]);
        }
        return ans;
    }
};