class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = nums.size();
        for(int i = 0 ; i<= total ;i++){
            int flag = 0;
            for(int j = 0 ; j < total; j++){
            if(nums[j] == i){
            flag++;
            break;
             }
           }
           if(flag == 0){return i;}
        }
    return -1;
    }
};