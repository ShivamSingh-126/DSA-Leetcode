class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) 
    {
        int n=nums.size();
        int mini=nums[0];
        int maxi=nums[0];

        for(int i=0;i<n;i++)
        {
            maxi = max(maxi,nums[i]);
            mini = min(mini,nums[i]);
        }
        return 1L * (maxi-mini) * k;
    }
};