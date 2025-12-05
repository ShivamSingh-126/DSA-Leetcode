class Solution {
public:
    int countPartitions(vector<int>& nums) {
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
    }
};