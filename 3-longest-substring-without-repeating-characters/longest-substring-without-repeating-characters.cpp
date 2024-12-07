#include <algorithm> 
class Solution {
public:

    bool findChar(char ch, string str){
        for(int i = 0 ; i< str.length(); i++){
            if(ch == str[i]){
                return false;
            }
        }
        return true;
    }

    int lengthOfLongestSubstring(string s) {
        if(s.length() == 1){
            return 1;
        }
        string str = "";
        size_t ans = 0;
        for(int i = 0 ; i< s.length() ; i++){
            for(int j =i ; j < s.length(); j++){
                if(findChar(s[j], str)){
                    str.push_back(s[j]);
                }else{
                    ans = max(ans, str.length());
                    str = "";
                    break;
                }
            }
        }

        return ans;
    }
};