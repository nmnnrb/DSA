class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0; 
        int leftpetrol = 0;
        int needpetrol = 0;

        for(int i = 0 ; i< gas.size() ; i++){
            leftpetrol += gas[i] - cost[i];
            if(leftpetrol < 0){
                needpetrol += leftpetrol;
                start =i+1;
                leftpetrol = 0;
            }
        } 
        if(leftpetrol + needpetrol >= 0){
            return start;
        }

        return -1;
    }
};