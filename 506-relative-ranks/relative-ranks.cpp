class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> temp = score;
        sort(temp.begin(), temp.end(), greater<int>());
        vector<string> medal =  {"Gold Medal", "Silver Medal", "Bronze Medal"};
        unordered_map<int, string> mapping;
        for(int i = 0 ;i < temp.size() ; i++){
            if(i < 3){
                mapping[temp[i]] = medal[i];
            }else{
                mapping[temp[i]] = to_string(i+1);
            }
        }
        vector<string> result;
        for(int i : score){
            result.push_back(mapping[i]);
        }
        return result;
    }
};