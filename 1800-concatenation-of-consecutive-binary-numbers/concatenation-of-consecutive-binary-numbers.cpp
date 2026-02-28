class Solution {
public:
    int concatenatedBinary(int n) {
        int mod = 1e9 + 7;
        long number = 0;
        
        for (int val = 1; val <= n; val++) {
            int digits = log2(val) + 1;

            number = ((number << digits) % mod + val) % mod;
        }
        return number;
    }
};