struct order{
    bool operator()(const string &a, const string &b){
        if(a.length() > b.length()){
            return true;
        }else if(a.length() < b.length()){
            return false;
        }else{
            return a>b ;
        }
    }
};

class Solution {
public:
    
    string kthLargestNumber(vector<string>& nums, int k) {
    //     vector<int> arr;
    //     for(int i = 0 ; i< nums.size() ;i++){
    //         if(!nums.empty()){
    //         arr.push_back(stoll(nums[i]));
    //         }
    //     }
    // sort(arr.begin() , arr.end());
    // int n = nums.size();
    // string ans = to_string(arr[n-k]);
    // if(k>0&& k< nums.size()){
    //     return ans;
        
    //     }else{
    //         return "";
    //     }
    order cmp;
    priority_queue<string, vector<string> ,order> pq;

    for(int i =0 ; i< k ; i++){
        pq.push(nums[i]);
    }
    for(int i = k ; i <nums.size();i++){
        if(cmp(nums[i], pq.top())){
            pq.push(nums[i]);
            pq.pop();
        }
    }
    return pq.top();
    }
};