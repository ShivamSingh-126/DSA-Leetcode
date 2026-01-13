class Solution {
public:
    int climbStairs(int n) 
    {
        if (n <= 1) return 1;

        int sl2 = 1, sl1 = 1;
        for (int i = 2; i <= n; i++) {
            int curr = sl1 + sl2;
            sl2 = sl1;
            sl1 = curr;
        }
        return sl1;     
    }
};