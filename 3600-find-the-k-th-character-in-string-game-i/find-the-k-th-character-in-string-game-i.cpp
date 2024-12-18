class Solution {
public:

    string generatestring(int k){
        string s ="a";
        while(s.size() <= k){
            string temp = s;
            for(int i = 0 ; i< temp.length();i++){
                temp[i] += 1;
            }
            s = s+ temp;
        }
        return s;
    }

    char kthCharacter(int k) {
        string s = generatestring(k);
        return s[k-1];
    }
};