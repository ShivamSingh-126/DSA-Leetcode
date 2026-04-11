class Solution {
public:
    int minimumDistance(vector<int>& nums) 
    {
        int n=nums.size();
        int mini=INT_MAX;
        unordered_map<int,vector<int>>mp;   // number of vector

        for(int k=0;k<n;k++)
        {
            mp[nums[k]].push_back(k);
            
            if(mp[nums[k]].size() >= 3)
            {
                vector<int> & idx=mp[nums[k]];  // index vector

                int len=idx.size();

                int i=idx[len-3];

                mini=min(mini,2*(k-i));
            }
        }
        return mini == INT_MAX ? -1 : mini;
    }
};