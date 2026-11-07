class Solution {
public:
    int solveMem(int i, vector<int>& nums, int p, vector<vector<int>>& dp) {
        int n = nums.size();

        if (i >= n)
            return 0;

        if (dp[i][p + 1] != -1)
            return dp[i][p + 1];

        int take = 0;

        if (p == -1 || nums[i] > nums[p]) {
            take = 1 + solveMem(i + 1, nums, i, dp);
        }

        int skip = solveMem(i + 1, nums, p, dp);

        return dp[i][p + 1] = max(take, skip);
    }
    
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solveMem(0, nums, -1, dp);
    }
};