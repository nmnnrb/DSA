class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> memo;
        return wordBreakHelper(s, wordSet, memo);
    }
    
private:
    vector<string> wordBreakHelper(string s, unordered_set<string>& wordSet, unordered_map<string, vector<string>>& memo) {
        if (memo.count(s)) {
            return memo[s];
        }
        
        vector<string> result;
        if (wordSet.count(s)) {
            result.push_back(s);
        }
        
        for (int i = 1; i < s.size(); ++i) {
            string right = s.substr(i);
            if (wordSet.count(right)) {
                string left = s.substr(0, i);
                vector<string> leftResult = wordBreakHelper(left, wordSet, memo);
                for (const string& l : leftResult) {
                    result.push_back(l + " " + right);
                }
            }
        }
        
        memo[s] = result;
        return result;
    }
};
