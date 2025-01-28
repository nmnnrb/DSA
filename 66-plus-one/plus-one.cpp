class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // int size = digits.size() -1 ;


        // if(digits[size] + 1 == 10){
        //     vector<int> ans;
        //     if(size > 1){
        //         digits[0] = 1;
        //         for(int i = 1 ; i< digits.size() ; i++){
        //             digits[i] = 0;
        //         }

        //         digits.push_back(0);
        //         return digits;
        //     }else{
        //         ans.push_back(1);
        //         ans.push_back(0);
        //         return ans;
        //     }
        // }


        // digits[size] +=1;
        // return digits;


        int carry = 1;
        int size = digits.size() -1 ;
        for(int i = size; i>=0; i--){

           int sume = digits[i] + carry;
           int digi = sume %10;
           carry = sume/10;
           
           digits[i] = digi;
          
        }

        if(carry > 0){
            vector<int> ans;
            ans.push_back(carry);
            for(int i = 0; i<= size ; i++){
                ans.push_back(digits[i]);
            }
            return ans;
        }
        return digits;
    }
};