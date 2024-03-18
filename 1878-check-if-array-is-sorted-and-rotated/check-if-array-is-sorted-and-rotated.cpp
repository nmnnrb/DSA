class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
    int count =0;
    for(int i =1; i< nums.size();i++){
        if(nums[i-1] > nums[i]){
            count++;
        }
    }
    if(nums[0] < nums[n-1]){
        count++;
    }
if(count <= 1){
    return true;
}else 
  return false;
 
    

        // int n=nums.size();
        // int cnt=0;
        // for(int i=1;i<n;i++){
        //     if(nums[i-1]>nums[i]){
        //         cnt++;
        //     }
        // }
        // if(nums[n-1]>nums[0]){
        //     cnt++;
        // }
        // return cnt<=1;
        }
};