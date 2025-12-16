class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long count = 1;
        long long flag = 1;
        for (int i = 1; i < n; i++) {
            if (prices[i - 1] - prices[i] == 1) {
                flag++;
            } else {
                flag = 1;
            }
            count += flag;
        }
        return count;
    }
};