class Solution {
public:
    int countTriplets(vector<int>& arr) {
         int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; ++i) {
        int xorSum = 0;
        for (int k = i; k < n; ++k) {
            xorSum ^= arr[k];
            if (xorSum == 0 && k > i) {
                count += (k - i);
            }
        }
    }

    return count;
    }
};