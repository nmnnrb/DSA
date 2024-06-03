class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0; // pointer for s
        int j = 0; // pointer for t
        
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                j++;
            }
            i++;
        }
        
        // The remaining characters in t from index j to the end need to be appended
        return t.size() - j;
    }
};
