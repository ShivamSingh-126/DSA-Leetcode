class Solution {
public:
    int concatenatedBinary(int n) {
        /*
        int mod = 1e9 + 7;
        long number = 0;

        for (int val = 1; val <= n; val++) {
            int digits = log2(val) + 1;

            number = ((number << digits) % mod + val) % mod;
        }
        return number;
        */
        int mod = 1e9 + 7;
        long number = 0;
        int digits=0;
        for (int val = 1; val <= n; val++) 
        {
            if((val & (val-1))==0)
            digits++;
            number = ((number << digits) % mod + val) % mod;
        }
        return number;
    }
};