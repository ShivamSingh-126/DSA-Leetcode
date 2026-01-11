class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<vector<int>> ans;
        unordered_set<int> chk(nums1.begin(), nums1.end());
        unordered_set<int> chk2(nums2.begin(), nums2.end());

        vector<int> v1, v2;

        for(auto y : chk)
        {
            if(!chk2.count(y))
            {
                v1.push_back(y);
            }
        }
        for(auto y : chk2)
        {
            if(!chk.count(y))
            {
                v2.push_back(y);
            }
        }

        return {v1,v2};
    }
};