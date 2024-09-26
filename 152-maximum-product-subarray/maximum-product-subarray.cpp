class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr = nums[0];
        int currmin = nums[0];
        int maxi = nums[0];
        for(int i = 1 ; i< nums.size();i++){
            if(nums[i] < 0){
                swap(curr,currmin);
            }
            curr = max(nums[i] , curr *  nums[i]);
            currmin = min(nums[i] , currmin *  nums[i]);
            maxi = max(curr, maxi);
        }

        return maxi;
    }
};