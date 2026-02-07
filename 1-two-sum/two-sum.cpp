class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        /*
        int n=nums.size();
        // unordered_map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    return {i,j};
                }
            }
        }
        return {-1,-1};
        */
        /*
        int n=nums.size(),numsearch=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp.insert({nums[i],i});
        }        
        for(int i=0;i<n;i++)
        {
            int numsearch=target-nums[i];
            if(mp.find(numsearch) != mp.end() && mp[numsearch] != i)
            {
                return {mp[numsearch],i};
            }
        }
        return {-1,-1};
        */
        int n=nums.size(),numsearch=0;
        unordered_map<int,int>mp;       
        for(int i=0;i<n;i++)
        {
            int numsearch=target-nums[i];
            if(mp.find(numsearch) != mp.end())
            {
                return {mp[numsearch],i};
            }
            mp[nums[i]]=i;
        }
        return {-1,-1};
    }
};