class Solution {
public:
    int countPartitions(vector<int>& nums) {
        /*
        int n = nums.size(), psum = 0, tsum = 0, count = 0;
        for (int i = 0; i < n - 1; i++) {
            psum += nums[i];
            for (int j = i + 1; j < n; j++) {
                tsum += nums[j];
            }
            if ((tsum - psum) % 2 == 0) {
                count++;
            }
            tsum = 0;
        }
        return count;
        */
        int n = nums.size(), total = 0, count = 0;
        for (int x : nums)
            total += x;
        int prefix = 0;
        for (int i = 0; i < n - 1; i++) {
            prefix += nums[i];

                int suffix = total - prefix;

            if ((suffix - prefix) % 2 == 0)
                count++;
        }
        return count;
    }
};