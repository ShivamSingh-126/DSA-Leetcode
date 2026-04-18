class Solution {
public:
    int res=0;
    int val;
    void solve(vector<int>& nums,unordered_map<int,int>&mp,int idx)
    {
        if(idx >= nums.size())
        {
            res++;
            return;
        }
        // exclude
        solve(nums,mp,idx+1);

        //include
        if(!mp[nums[idx]-val] && !mp[nums[idx]+val])
        {
            mp[nums[idx]]++;
            solve(nums,mp,idx+1);   // explore
            mp[nums[idx]]--;
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) 
    {
        val=k;
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        solve(nums,mp,0);
        return res-1;   // exclude empty subset
    }
};