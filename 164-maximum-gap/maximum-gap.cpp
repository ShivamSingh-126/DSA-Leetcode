class Solution {
public:
    int maximumGap(vector<int>& nums) 
    {
        // it optimised using bucket sort
        if(nums.size()<2)  return 0;
        int n=nums.size();
        sort(nums.begin(),nums.end());  //it takes O(n logn) 
        int ans=0,i=0;
        while(i<n-1)
        {
            ans=max(ans,nums[i+1]-nums[i]);
            i++;
        }
        return ans;
    }
};