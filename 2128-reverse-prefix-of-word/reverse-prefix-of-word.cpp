class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = 0;
        for(int i = 0 ; i < word.length(); i++){
            if(ch == word[i]){
                index = i;
                break;
            }
        }

        for(int i = 0 ; i<= index ; i++){
            char temp = word[i];
            word[i] = word[index];
            word[index] = temp;
            index--;
        }
        return word;
    }
};