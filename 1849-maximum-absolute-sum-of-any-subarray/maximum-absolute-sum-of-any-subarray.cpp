class Solution {
public:
    int maxsum(vector<int>& nums)
    {
        int bestending=nums[0];
        int n=nums.size();
        int res=nums[0];

        for(int i=1;i<n;i++)
        {
            int v1 = bestending + nums[i];
            int v2 = nums[i];

            bestending = max(v1,v2);
            res=max(res,bestending);
        }
        return res;
        
    }
        
    int minsum(vector<int>& nums)
    {
        int bestending=nums[0];
        int n=nums.size();
        int res=nums[0];

        for(int i=1;i<n;i++)
        {
            int v1 = bestending + nums[i];
            int v2 = nums[i];

            bestending = min(v1,v2);
            res=min(res,bestending);
        }
        return abs(res);
        
    }
    int maxAbsoluteSum(vector<int>& nums) 
    {
        if(nums.size() == 1)  return abs(nums[0]);

        int sum = max(maxsum(nums),minsum(nums));
        return sum;
    }
};