class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {/*
        // brute force
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]==nums[j] && abs(i-j)<=k) return true;
            }
        }
        return false;
        */
        unordered_map<int,int>mapp;

        for(int i=0;i<nums.size();i++)
        {
            if(mapp.count(nums[i]) && (i-mapp[nums[i]])<=k)
            {
                return true;           
            }

            mapp[nums[i]]=i;        // update the index
        }
        return false;
    }
};