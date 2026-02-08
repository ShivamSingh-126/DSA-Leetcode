class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) 
    {/*  This code is for single merge

        vector<long long> ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
           long long keep=nums[i];

            while(i+1 <n && nums[i] == nums[i+1])
            {
               keep+=nums[i+1];
                i++;
            }
            ans.push_back(keep);
        }
        return ans;
        */
        /*  also not optimal

        vector<long long> ans(nums.begin(),nums.end());
        int i=0,sum=0;
        while(i+1 < ans.size())
        {
            if(ans[i] == ans[i+1])
            {
                ans[i]+=ans[i+1];
                ans.erase(ans.begin()+i+1);

                if(i > 0) i--;
            }
            else
            {
                i++;
            }
        }
        return ans;
        */
        vector<long long> ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            long long keep=nums[i];
            while(!ans.empty() && ans.back()==keep)
            {
                keep+=ans.back();
                ans.pop_back();
            }
            ans.push_back(keep);
        }
        return ans;
    }
};