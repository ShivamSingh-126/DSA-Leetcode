class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0,r=n-1,mindiff=INT_MAX;
        while(l+k-1 < n)
        {
            int r=l+k-1;
            int diff=nums[r]-nums[l];
            mindiff=min(diff,mindiff);
            l++;           
        }
        return mindiff;
    }
};