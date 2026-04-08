class Solution {
public:
    int n;
    void backtrack(vector<int>& nums,vector<vector<int>> &ans,vector<int>&temp,int index)
    {
        if(temp.size() >= 2)
        {
            ans.push_back(temp);
        }
        unordered_set<int>st;
        for(int i=index;i<n;i++)
        {
            if((temp.empty() || nums[i] >= temp.back()) && (st.find(nums[i])== st.end()))
            {
                temp.push_back(nums[i]);  // Tick mark the elemnt
                backtrack(nums,ans,temp,i+1);       // explore this
                temp.pop_back();
                st.insert(nums[i]);
            }

        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        n=nums.size();
        vector<vector<int>> ans;
        vector<int>temp;

        backtrack(nums,ans,temp,0);
        return ans;
    }
};