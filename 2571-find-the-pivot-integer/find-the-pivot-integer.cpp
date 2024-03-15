class Solution {
public:
    int pivotInteger(int n) {
            int ans = -1;
   int sum = n * (n+1) / 2;
   int pref=0;
   for (int i = 0; i <= n; i++)
   {if(pref+i == sum - pref){
    ans = i; }    
    pref += i;
   }
   return ans;
   
    }
};