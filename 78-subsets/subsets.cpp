class Solution {
public:
    void solve(vector<int>& nums, int idx,  vector<vector<int>>&ans,
        vector<int>& temp)
    {
        if(idx == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);   //  include
        solve(nums,idx+1,ans,temp);
        temp.pop_back();           // exclude
        solve(nums,idx+1,ans,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        /*
        int n=nums.size();
        int subset=(1 << n);
        vector<vector<int>>ans;
        for(int i=0;i<subset;i++)
        {
           vector<int>list;
            for(int j=0;j<n;j++)
            {
                if(i & (1 << j))
                {
                    list.push_back(nums[j]);
                }
            }
            ans.push_back(list);
        }
        return ans;
        */       
        vector<vector<int>>ans;
        vector<int>temp;
        solve(nums,0,ans,temp);
        return ans;

    }
};