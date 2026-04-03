class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) 
    {
        int n=nums1.size();
        unordered_map<int,int> mp;

        for(auto &val : nums1)
        {
            mp[val]++;
        }
        for(auto &val:nums2)
        {
            mp[val]--;
        }
        int swap=0;
        for(auto &val : mp)
        {
            if(val.second %2 !=0) return -1;

            swap+=abs(val.second);
        }
        return swap/4;
    }
};