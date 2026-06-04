class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n=nums.size();
        int low=0,ans=INT_MAX;
        int sum=0;
        for(int high =0;high<n;high++)
        {
            sum +=nums[high];
            while(sum >= target)
            {
                ans=min(ans,high-low+1);

                sum -=nums[low];
                low++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};