#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        // Step 1: Calculate frequency of each letter in the letters vector
        vector<int> letterCount(26, 0);
        for (char letter : letters) {
            letterCount[letter - 'a']++;
        }

        // Step 2: Calculate score of each word
        vector<int> wordScores(words.size(), 0);
        vector<vector<int>> wordLetterCount(words.size(), vector<int>(26, 0));

        for (int i = 0; i < words.size(); ++i) {
            for (char c : words[i]) {
                wordLetterCount[i][c - 'a']++;
                wordScores[i] += score[c - 'a'];
            }
        }

        // Step 3: Use backtracking to find the maximum score
        return backtrack(words, letterCount, wordScores, wordLetterCount, 0);
    }

private:
    int backtrack(vector<string>& words, vector<int>& letterCount, vector<int>& wordScores,
                  vector<vector<int>>& wordLetterCount, int index) {
        if (index == words.size()) {
            return 0;
        }

        // Option 1: Skip the current word
        int skip = backtrack(words, letterCount, wordScores, wordLetterCount, index + 1);

        // Option 2: Use the current word (if possible)
        bool canUse = true;
        for (int j = 0; j < 26; ++j) {
            if (wordLetterCount[index][j] > letterCount[j]) {
                canUse = false;
                break;
            }
        }

        int use = 0;
        if (canUse) {
            // Subtract the letters used by this word
            for (int j = 0; j < 26; ++j) {
                letterCount[j] -= wordLetterCount[index][j];
            }
            use = wordScores[index] + backtrack(words, letterCount, wordScores, wordLetterCount, index + 1);
            // Restore the letters after the recursion returns
            for (int j = 0; j < 26; ++j) {
                letterCount[j] += wordLetterCount[index][j];
            }
        }

        // Return the maximum score possible by either using or skipping the current word
        return max(skip, use);
    }
};
