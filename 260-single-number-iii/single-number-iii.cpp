class Solution {
public:
    static vector<int> singleNumber(vector<int>& nums) {
        int XOR=accumulate(nums.begin(), nums.end(), 0, bit_xor<>());
        //XOR=a^b

        // Find first bit=1 for XOR
        // same as using builtin function
        // int i=31-__builtin_clz(XOR);
        int i=31;
        while (((XOR >> i) & 1) == 0)
            i--;
        // i-th bit=1

        int A=0, B=0;
        for(int x: nums){
            if (((x >> i) & 1) == 0)
                A^=x;
            else
                B^=x; 
        }
    //    A^=XOR, B^=XOR;
        return {A, B};
    }
};