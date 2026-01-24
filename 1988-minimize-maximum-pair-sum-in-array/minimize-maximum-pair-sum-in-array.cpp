class Solution {
public:
    int minPairSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int minsum=INT_MIN;
        int sum=0;
        int l=0,r=n-1;
        while(l < r)
        {   int sum=nums[l]+nums[r];
            minsum=max(minsum,sum);
            l++;
            r--;
        }
        return minsum;
    }
};