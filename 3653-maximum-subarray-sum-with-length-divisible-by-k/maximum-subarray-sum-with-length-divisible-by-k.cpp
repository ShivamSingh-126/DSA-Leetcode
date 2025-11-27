class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        /*  it gives TLE
        int n = nums.size();
        long long sum = 0, maxsum = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];

                int len = j - i + 1;
                if (len % k == 0)
                    maxsum = max(sum, maxsum);
            }
        }
        return maxsum;
        */
        int n = nums.size();
        vector<long long> minprefix(k, LLONG_MAX);
        long long prefixsum = 0;
        minprefix[0] = 0;
        long long ans = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            prefixsum += nums[i];
            int count = (i + 1) % k;
            if (minprefix[count] != LLONG_MAX) {
                ans = max(ans, prefixsum - minprefix[count]);
            }
            minprefix[count]=min(minprefix[count],prefixsum);
        }
        return ans;
    }
};