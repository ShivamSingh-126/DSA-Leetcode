class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n=nums.size(),cursum=0,mini=INT_MAX;
        int low=0,high=0;
        while(high<n)
        {   // find cursum and inc window size
            cursum+=nums[high];
            high++;

            // try to reduce curwinsize
            while(cursum >= target)
            {
                int cws=high-low;
                mini=min(mini,cws);

                cursum-= nums[low];
                low++;
            }
        }
        return mini == INT_MAX ? 0: mini;
    }
};