class Solution {
public:
    int minimumSum(vector<int>& nums) 
    {
        int n=nums.size();
        int mini=INT_MAX;
        for(int j=1;j<n-1;j++)
        {
            int lmin=INT_MAX;
            int rmin=INT_MAX;

            for(int i=0;i<j;i++)
            {
                if(nums[i] < nums[j])
                {
                    lmin=min(lmin,nums[i]);
                }
            }
            for(int k=j+1;k<n;k++)
            {
                if(nums[k] < nums[j])
                {
                    rmin=min(rmin,nums[k]);
                }
            }
            if(lmin != INT_MAX && rmin!= INT_MAX)
            {
                mini=min(mini,lmin+rmin+nums[j]);
            }
        }
        return mini != INT_MAX ? mini : -1;
    }
};