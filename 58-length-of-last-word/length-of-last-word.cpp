class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        bool check = false;
        for(int i = s.length() -1 ; i>= 0 ;i--){
            if(s[i] != ' '){
                check = true;
                count++;
            }else{ if(check){
                break;
                        }
                 }

        }
        return count;
    }
};