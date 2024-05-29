class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        while (s != "1") {
            if (s.back() == '0') {
                // If the binary number is even, divide by 2 (remove the last character)
                s.pop_back();
            } else {
                // If the binary number is odd, add 1
                int carry = 1;
                for (int i = s.size() - 1; i >= 0 && carry; --i) {
                    if (s[i] == '1') {
                        s[i] = '0';
                    } else {
                        s[i] = '1';
                        carry = 0;
                    }
                }
                if (carry) {
                    s = '1' + s;
                }
            }
            ++steps;
        }
        return steps;
    }
};