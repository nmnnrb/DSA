class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int s = 0, e = prices.size() - 1;
        // int maxi = 0;
        // while (e > s) {
        //     if (prices[e] > prices[s]) {
        //         if (abs(prices[s] - prices[e]) > 0) {
        //             maxi = max(maxi, abs(prices[s] - prices[e]));
        //         }
        //     }
        //     s++, e--;
        // }

        // return maxi;

        int buyPrice = prices[0];
        int sum = 0;

        for(int i = 0; i< prices.size() ; i++){
            if(buyPrice > prices[i]){
                buyPrice = prices[i];
            }
            sum = max ( sum, prices[i] - buyPrice);
        }

        return sum;

    }
};