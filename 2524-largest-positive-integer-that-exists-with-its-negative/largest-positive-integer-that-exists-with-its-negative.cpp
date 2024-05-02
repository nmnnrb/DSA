class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int i = 0 ;i < nums.size() ; i++){
            count[nums[i]] +=1;
        }
        // for that highest ocuuring is negative exist
        int maxpos = -1;

        for(int num : nums){
            if(num > 0 && count[-num] > 0){
                maxpos = max(num, maxpos);
            }
        }
        return maxpos;
    }
};