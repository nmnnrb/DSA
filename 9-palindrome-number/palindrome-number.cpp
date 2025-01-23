class Solution {
public:
    bool isPalindrome(int x) {

       

        string s = to_string(x);
        
        int st = 0 , e = s.length() -1;

        while(st<e){
            if(s[st] != s[e]){
                return false;
            }else{
                st++ , e--;
            }
        }

    return true;

    }
};