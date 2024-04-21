class Solution {
public:
    bool isValid(string s) {
       int i = 0;
       stack<int> st;
       while(i< s.length()){
            char ch = s[i];
            if((ch == '(' ) || (ch == '[' ) ||(ch == '{' )  ){
                st.push(ch);
            }else if(st.empty()){
                return false;
            }else {
                char chr = st.top();
                if( (chr == '(' && ch == ')') || (chr == '{' && ch == '}')
                   ||  (chr == '[' && ch == ']') ){
                        st.pop();
                   }else{
                    return false;
                   }
            }
        i++;
       }

       if(!st.empty()){
        return false;
       }
        return true;
    }
};