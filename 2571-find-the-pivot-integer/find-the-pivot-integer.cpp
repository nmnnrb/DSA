class Solution {
public:
    int pivotInteger(int n) {
        int sum =  n * (n+1) / 2 ;
        int ans = -1;
        int pref = 0;
        for(int i = 0 ; i<=n; i++){
            if(pref +i == sum - pref){
                return i;
               
            }
             pref += i;
        }
        return -1;
    }
};