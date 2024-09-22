class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long add = 0;
        for(int i = 0 ; i< nums.size() ; i++){
            add += nums[i];
        }

        long long first = abs(goal - add);
    return (first + limit -1) / limit;
    }
};