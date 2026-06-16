class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        int n=nums.size();
        int zero=0;
        int ones=0;
        int res=0;
        unordered_map<int,int>mpp;

        for(int i=0;i<n;i++)
        {
            if(nums[i] == 0) zero++;
            else ones++;

            int diff=zero-ones;
            if(diff  == 0)
            {
                res = max(res,i+1);
                continue;
            }

            if(mpp.find(diff) == mpp.end())
            {
                mpp[diff]=i;
            }
            else
            {
                int idx=mpp[diff];
                int len=i-idx;
                res=max(len,res);
            }
        }
        return res;
    }
};