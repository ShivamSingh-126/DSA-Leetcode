class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) 
    {
        int n=nums.size();
        vector<int>target;
        for(int i=0;i<n;i++)
        {
            int idx=index[i];
            target.insert(target.begin()+idx,nums[i]);
        }
        return target;
    }
};