class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // There are 26 letters in the alphabet
        vector<int> minFreq(26, INT_MAX);
        
        // Update minFreq based on the frequency of characters in each word
        for (const string& word : words) {
            vector<int> charCount(26, 0);
            for (char ch : word) {
                charCount[ch - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                minFreq[i] = min(minFreq[i], charCount[i]);
            }
        }
        
        // Collect the common characters
        vector<string> result;
        for (int i = 0; i < 26; ++i) {
            while (minFreq[i] > 0) {
                result.push_back(string(1, i + 'a'));
                minFreq[i]--;
            }
        }
        
        return result;
    }
};
