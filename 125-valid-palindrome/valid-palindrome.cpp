class Solution {
public:
 
    void lower(string &s){
        for(int i = 0; i < s.length();i++){
            char ch = s[i];
            if(ch >= 'A' && ch <='Z'){
            ch = ch -'A' + 'a';
            }
            s[i] = ch;
        }
    }
   bool valid(char c){
        if((c >='a' && c <='z') || (c >='0' && c <= '9') || c >= 'A' && c<='Z' ){
            return 1;
        }else {
            return 0;
    }
}

    bool isPalindrome(string s) {
    string temp = "";
    for(int i = 0 ; i < s.length(); i++){
        if(valid(s[i])){
            temp.push_back(s[i]);
        }
    }
lower(temp);
int i = 0 ;
int e = temp.length() -1;

   while(i < e){
    if(temp[i] == temp[e]){

        i++ , e--;
    }else{
        return false;
    }
   }

return true;

    }
};