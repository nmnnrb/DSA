class Solution {
public:
    int numDifferentIntegers(string word) {

        string s = "";
        int count = 0;


    for(char c : word){
        if(isdigit(c)){
            s+=c;
        }else{
            s+=" ";
        }
    }  
    set<string> uniqueNum ;
    string num ="";

    for(char c : s){
        if(c == ' '){
              if (!num.empty()) { 
            while(num.length() > 1 && num[0] == '0'){
                num.erase(0,1);
            }
            uniqueNum.insert(num);
              }
            num="";
        }else{
            num +=c;
        }
    }

    if(!num.empty()){
          while(num.length() > 1 && num[0] == '0'){
                num.erase(0,1);
            }
            uniqueNum.insert(num);
    }



        return uniqueNum.size();



        // string s ="";
        // int count = 0;
        // for(char c : word){
        //     if(!isdigit(c)){
        //         s+=" ";
        //     }else{
        //         s+=c;
        //     }
        // }
        // vector<long long> ans;
        // string num ="";
        // for(int i = 0 ; i< s.length() ; i++){
        //     if(s[i] == ' ' ){
        //         if(num.length() > 0  ){
        //             ans.push_back(stoll(num));
        //         }
        //         num = "";
        //     }else{
        //         num += s[i];
        //     }
        // }

        // if(num.length() > 0  ){
        //     ans.push_back(stoll(num));
        // }

        // if(ans.size() == 0){
        //     return 0;
        // }

        // for(int i  = 0; i< ans.size() ; i++){
        //     for(int j = i+ 1 ; j< ans.size() ; j++){
        //         if(ans[i] == ans[j]){
        //             count++;
                  
        //         }
        //     }
        // }
        //   set<long long> uniqueElements(ans.begin(), ans.end());
        // return  uniqueElements.size();

    }
};