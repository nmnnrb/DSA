class Solution {
public:
    int pivotInteger(int n) {
        int sum = 0;
        int ans = -1;

        for(int i= 0; i<=n ; i++){
            sum += i;
            int leftsum = 0;
            for(int j = i; j <= n; j++){
                leftsum += j;
            }
            if(sum == leftsum){
                ans = i;
            }

        }
        return ans;
    }
};