class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> result(n);
        for(int i=0;i<n;i++)
        {
            int idx=nums[i];
            int newidx=(i+idx)%n;

            if(newidx < 0)
            {
                newidx+=n;
            }
            result[i]=nums[newidx];
        }
        return result;
    }
};